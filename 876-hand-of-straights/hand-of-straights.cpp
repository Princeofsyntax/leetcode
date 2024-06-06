class Solution {
public:
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> cardCounts;
        for (int card : hand) {
            ++cardCounts[card]; // Increment the count for each card.
        }
      
        sort(hand.begin(), hand.end());
      
        for (int card : hand) {
            // If the current card is still in count map (i.e., needed to form a group).
            if (cardCounts.count(card)) {
                // Attempt to create a group starting with the current card.
                for (int nextCard = card; nextCard < card + groupSize; ++nextCard) {
                    // If the next card in the sequence is missing, can't form a group.
                    if (!cardCounts.count(nextCard)) {
                        return false;
                    }
                    // Decrement count for the current card in the sequence.
                    if (--cardCounts[nextCard] == 0) {
                        cardCounts.erase(nextCard); // Remove the card from count map if count reaches zero.
                    }
                }
            }
        }
      
        // If all cards can be grouped, return true.
        return true;
    }
};