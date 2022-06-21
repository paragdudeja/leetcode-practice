class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1;
        int secondLastFruit = -1;
        int lastFruitCount = 0;
        int currMax = 0;
        int maxFruits = 0;
        
        for (const int &fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit)
                currMax++;
            else
                currMax = lastFruitCount + 1; // last fruit + new fruit
            
            if (fruit == lastFruit)
                lastFruitCount++;
            else
                lastFruitCount = 1; 
            
            if (fruit != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            
            maxFruits = max(maxFruits, currMax);
        }
        
        return maxFruits;
    }
};