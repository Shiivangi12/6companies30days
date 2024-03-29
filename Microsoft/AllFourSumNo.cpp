 vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
         vector<vector<int>>result;
        sort(arr.begin(),arr.end());
        int size = arr.size();
        if(size == 0){
            return result;
        }
        for(int i=0; i<size-3; i++){
            for(int j=i+1; j<size-2; j++){
                int start = j+1, end = size - 1;
                while(start < end){
                    int s1 = arr[i] + arr[j];
                    int s2 = arr[start] + arr[end];
                    int sum = s1 + s2;
                    if(sum == k){
                        vector<int>temp = {arr[i],arr[j],arr[start],arr[end]};
                        result.push_back(temp);
                        while(start < end and arr[start] == temp[2]){
                            start++;
                        }
                        while(start < end and arr[end] == temp[3]){
                            end--;
                        }
                    }
                    else if(sum < k){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
                while(j < size and arr[j] == arr[j+1]){
                    j++;
                }
            }
            while(i < size and arr[i] == arr[i+1]){
                i++;
            }
        }
        return result;
    }
