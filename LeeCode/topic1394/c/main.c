int findLucky(int* arr, int arrSize){
    int hashSet[501]={0};
    for(int i=0;i<arrSize;i++){
        hashSet[arr[i]]++;
    }

    for(int i=500;i>=1;i--){
        if(i==hashSet[i]){
            return i;
        }
    }

    return -1;
}