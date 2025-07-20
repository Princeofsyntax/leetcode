struct TrieNode {
    map<string, TrieNode*> children; 
    // Pointer to the original path from the input vector. Null if it's an intermediate folder.
    const vector<string>* path_ref = nullptr; 
    bool to_be_deleted = false;
    ~TrieNode() {
        for (auto const& [key, val] : children) {
            delete val;
        }
    }
};

class Solution {
public:
    // Maps a structure representation to a unique integer ID.
    // The key is a vector of {child_name, child_structure_id} pairs.
    map<vector<pair<string, int>>, int> structure_to_id;
    
    // Maps a structure ID to all nodes that have this structure.
    map<int, vector<TrieNode*>> id_to_nodes;
    
    // Counter for assigning new structure IDs.
    int next_id = 1;
    
    int dfs_get_id(TrieNode* node) {
        if (node->children.empty()) {
            return 0;
        }

        vector<pair<string, int>> current_structure;
        // The map ensures children are processed in alphabetical order for a canonical signature.
        for (auto const& [name, child_node] : node->children) {
            int child_id = dfs_get_id(child_node);
            current_structure.push_back({name, child_id});
        }

        // Find an existing ID for this structure or assign a new one.
        if (structure_to_id.find(current_structure) == structure_to_id.end()) {
            structure_to_id[current_structure] = next_id++;
        }
        
        int my_id = structure_to_id[current_structure];
        id_to_nodes[my_id].push_back(node);
        return my_id;
    }

    void dfs_collect(TrieNode* node, bool parent_is_deleted, vector<vector<string>>& result) {
        if (!node) return;

        // A folder is deleted if it's the root of a duplicate structure OR its parent was deleted.
        bool is_deleted = node->to_be_deleted || parent_is_deleted;

        // If the current folder is not deleted and it represents a full path from the input.
        if (!is_deleted && node->path_ref) {
            result.push_back(*(node->path_ref));
        }

        for (auto const& [name, child_node] : node->children) {
            dfs_collect(child_node, is_deleted, result);
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        // 1. Build the Trie from the input paths.
        for (const auto& path : paths) {
            TrieNode* current = root;
                for (const string& folder_name : path) {
                    if (current->children.find(folder_name) == current->children.end()) {
                        current->children[folder_name] = new TrieNode();
                    }
                    current = current->children[folder_name];
                }
            current->path_ref = &path;
        }
         // 2. Assign structure IDs and group nodes by their structure.
        dfs_get_id(root);

        // 3. Mark all folders that are part of a duplicate structure.
        // We only consider structures with non-empty subfolders (ID > 0).
        for (auto const& [id, nodes] : id_to_nodes) {
            if (nodes.size() > 1) { // This structure is duplicated.
                for (TrieNode* node : nodes) {
                    node->to_be_deleted = true;
                }
            }
        }
        
        // 4. Collect the paths of all non-deleted folders.
        vector<vector<string>> result;
        dfs_collect(root, false, result);
        
        // 5. Clean up allocated memory for the Trie.
        delete root;

        return result;
    }
};