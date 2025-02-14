class ProductOfNumbers {
private:
    vector<int> prefixProducts;
public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }
    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1); 
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) {
            return 0; 
        }
        return prefixProducts.back() / prefixProducts[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */