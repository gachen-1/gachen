#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
#include<tuple>
using namespace std;
//problem 1

vector<vector<int>> gachen1(vector<vector<int>>& gaps){
     if (gaps.empty())
        return {};  //define a two dimensional vector gachen1 to store gaps
     
    sort(gaps.begin(), gaps.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });  //compare the first element of two vectors in gaps, sorting them in order
    vector<vector<int>> result; 
    
    vector<int> initial = gaps[0];  //store the first vector in gaps into initial
    for (int i=1; i<gaps.size(); i++)
    {
        if (initial[1]>=gaps[i][0]) {
            initial[1] = max(initial[1], gaps[i][1]);}//if the initial of second element is smaller, choose the larger second element to be the second element.
        else{
               result.push_back(initial);
               initial = gaps[i]; 
             }   
       }
    result.push_back(initial);//add the last initial to result
    gaps = result;
    return gaps;
}




//problem 2
//count:
vector<int> gachen2count(vector<int>& threenumbers){
    int a=0, b=0, c=0;
    for (int i=0; i<threenumbers.size(); i++){
        if (threenumbers[i] == 0) 
                a++;
        else if (threenumbers[i] == 2) 
                b++;
             else
                c++;
        }
    int x=0;
    for (int i=0; i<a; i++)
        threenumbers[x]=0;
        x++;
    for (int i=0; i<b; i++)
        threenumbers[x]=2;
        x++;
    for (int i=0; i<c; i++)
        threenumbers[x]=1;      
    
    
    return threenumbers;

    }
    

//Dutch flag
vector<int> gachen2Dutchflag(vector<int>& threenumbers){
      int left=0,current=0,right=threenumbers.size()-1;
      while(current<=right){
          if (threenumbers[current]==0){
               swap(threenumbers[left],threenumbers[current]);
               left++;
               current++;
          }
          else if (threenumbers[current]==2){
               swap(threenumbers[current],threenumbers[right]);
               right--;
          }
          else{
               current++;
          }
      }
      return threenumbers;
}




//problem 3
string gachen3biggest(vector<int>& numbers){
     if (numbers.empty())
        return" ";
    
    vector<string> str;
    for (int i=0; i<numbers.size(); i++){
       str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(),str.end(),[](const string& a, const string& b) {
        return a + b > b + a;
    });
    string result;
    for (int i=0; i<str.size(); i++){
        result=result+str[i];
         return result;
    }
}



//problem4
vector<vector<string>> gachen4Anagrams(vector<string>& words){
       unordered_map<string,vector<string>> map;
       if (words.empty())
            return {};
       
       for (int i=0; i<words.size(); i++){
           string key=words[i];
           sort(key.begin(),key.end());
           map[key].push_back(words[i]);
       }
        vector<vector<string>> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }
    return result;
}
     




//problem5
bool gachen5meetings(vector<vector<int>>& meetings){
        if (meetings.empty())
            return true;
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i=0; i<meetings.size()-1; i++){
            if (meetings[i][1]>meetings[i+1][0]){
                return false;
            }
        }
        return true;
 }


//problem6
//sort
vector<vector<int>> gachen6sort(vector<vector<int>> &points, int k){
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] < b[0]*b[0];
        });
        vector<vector<int>> result;
        for (int i=0; i<=k; i++){
            result.push_back(points[i]);
        }
        return result;
    }


//heap
vector<vector<int>> gachen6heap(vector<vector<int>> &points, int k){
        priority_queue<pair<int,int>> maxHeap;

    for (int i = 0; i < points.size(); ++i) {
        int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        if (maxHeap.size() < k) {
            maxHeap.push({distance, i});
        } else if (distance < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({distance, i});
        }
    }

    vector<vector<int>> result;
    for (int i = 0; i < k; ++i) {
        int index = maxHeap.top().second;
        result.push_back(points[index]);
        maxHeap.pop();
    }
    return result;
}






//problem7
vector<int> gachen7knumber(vector<int>& numbers, int k){
         unordered_map<int,int> frequency;
         for (int i=0; i<numbers.size(); i++){
             frequency[numbers[i]]++;
         }
         vector<pair<int,int>> pairs(frequency.begin(), frequency.end());
         sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) {
                return  a.second > b.second;
            }
            return a.first < b.first;
        });
         
         vector<int> result;
         for(int i=0; i<k; i++){
             result.push_back(pairs[i].first);
         }
         return result;
    }
         



//problem8
vector<int> gachen8karrays(vector<vector<int>>& arrays){
        using x=tuple<int, int, int>;
        priority_queue<x, vector<x>, greater<x>> minHeap; 
        for (int i=0; i<arrays.size(); i++){
            if (!arrays[i].empty()){
                minHeap.push({arrays[i][0], i, 0});
            }
       }
        
        vector<int> result;
        while (!minHeap.empty()){
            auto[value, array, elements] = minHeap.top();
            minHeap.pop();
            result.push_back(value);
            
            if (elements + 1 < arrays[array].size()){
                minHeap.push({arrays[array][elements + 1], array, elements + 1});
            }
        }
        return result;
    }


//problem9
int gachen9kthnumber(vector<int>& numbers,int k){
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i=0; i<numbers.size(); i++){
            minHeap.push(numbers[i]);
            if (minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }





    
//problem10
long long gachen10merge(vector<int>& values, vector<int>& temp, int left, int mid, int right){
    int i=left, j=mid+1, k=left;
    long long count=0;

    while (i<=mid && j<=right){
        if (values[i]<=values[j]){
            temp[k]=values[i];
            i++;
        }
        else{
            temp[k]=values[j];
            j++;
            count=count+(mid-i+1);
        }
            k++;
    }
    while (i<=mid){
        temp[k]=values[i];
        i++;
        k++;
    }
    while (j<=right){
        temp[k]=values[j];
        j++;
        k++;
    }
    for (int a=left; a<=right; a++){
        values[a]=temp[a];
    }
    return count;
}

long long gachen10sort(vector<int>& values, vector<int>& temp, int left, int right){
    if (left>=right)
        return 0;

    int mid=(left+right)/2;
    long long count=gachen10sort(values,temp,left,mid);
    count=count+gachen10sort(values,temp,mid+1,right);
    count=count+gachen10merge(values,temp,left,mid,right);
    return count;
}

long long gachen10inversions(vector<int>& values){
    if (values.empty())
        return 0;

    vector<int> temp(values.size());
    return gachen10sort(values,temp,0,values.size()-1);
}




//====================== 测试用的打印工具函数 ======================
void printVector(const vector<int>& v){
    cout << "[";
    for (int i=0; i<v.size(); i++){
        cout << v[i];
        if (i+1<v.size()) cout << ", ";
    }
    cout << "]";
}

void print2DVector(const vector<vector<int>>& v){
    cout << "[";
    for (int i=0; i<v.size(); i++){
        printVector(v[i]);
        if (i+1<v.size()) cout << ", ";
    }
    cout << "]";
}

void printStringVector(const vector<string>& v){
    cout << "[";
    for (int i=0; i<v.size(); i++){
        cout << v[i];
        if (i+1<v.size()) cout << ", ";
    }
    cout << "]";
}

void print2DStringVector(const vector<vector<string>>& v){
    cout << "[";
    for (int i=0; i<v.size(); i++){
        printStringVector(v[i]);
        if (i+1<v.size()) cout << ", ";
    }
    cout << "]";
}


//====================== 每道题的测试函数 ======================
void test1(){
    cout << "----- Problem 1: merge intervals -----" << endl;
    vector<vector<int>> gaps = {{1,3},{2,6},{8,10},{15,18}};
    cout << "input:  "; print2DVector(gaps); cout << endl;
    vector<vector<int>> result = gachen1(gaps);
    cout << "output: "; print2DVector(result); cout << endl;
    cout << "expect: [[1, 6], [8, 10], [15, 18]]" << endl << endl;
}

void test2(){
    cout << "----- Problem 2: sort 0/1/2 array -----" << endl;
    vector<int> arr1 = {2,0,2,1,1,0};
    vector<int> arr2 = arr1; // 复制一份，两个版本分别测试
    cout << "input:  "; printVector(arr1); cout << endl;

    vector<int> countResult = gachen2count(arr1);
    cout << "count sort output:      "; printVector(countResult); cout << endl;

    vector<int> dutchResult = gachen2Dutchflag(arr2);
    cout << "dutch flag output:      "; printVector(dutchResult); cout << endl;
    cout << "expect (sorted 0/1/2):  [0, 0, 1, 1, 2, 2]" << endl << endl;
}

void test3(){
    cout << "----- Problem 3: largest number formed by concatenation -----" << endl;
    vector<int> numbers = {3,30,34,5,9};
    cout << "input:  "; printVector(numbers); cout << endl;
    string result = gachen3biggest(numbers);
    cout << "output: " << result << endl;
    cout << "expect: 9534330" << endl << endl;
}

void test4(){
    cout << "----- Problem 4: group anagrams -----" << endl;
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    cout << "input:  "; printStringVector(words); cout << endl;
    vector<vector<string>> result = gachen4Anagrams(words);
    cout << "output: "; print2DStringVector(result); cout << endl;
    cout << "expect groups: [eat,tea,ate], [tan,nat], [bat] (顺序可能不同)" << endl << endl;
}

void test5(){
    cout << "----- Problem 5: can attend all meetings -----" << endl;
    vector<vector<int>> overlapping = {{0,30},{5,10},{15,20}};
    vector<vector<int>> nonOverlapping = {{7,10},{2,4}};
    cout << "input(overlap):     "; print2DVector(overlapping); cout << endl;
    cout << "output: " << (gachen5meetings(overlapping) ? "true" : "false") << " (expect: false)" << endl;
    cout << "input(no overlap):  "; print2DVector(nonOverlapping); cout << endl;
    cout << "output: " << (gachen5meetings(nonOverlapping) ? "true" : "false") << " (expect: true)" << endl << endl;
}

void test6(){
    cout << "----- Problem 6: k closest points to origin -----" << endl;
    vector<vector<int>> points1 = {{1,3},{-2,2},{2,-2},{5,8}};
    vector<vector<int>> points2 = points1;
    int k = 2;
    cout << "input:  "; print2DVector(points1); cout << ", k=" << k << endl;

    vector<vector<int>> sortResult = gachen6sort(points1, k);
    cout << "sort version output: "; print2DVector(sortResult); cout << endl;

    vector<vector<int>> heapResult = gachen6heap(points2, k);
    cout << "heap version output: "; print2DVector(heapResult); cout << endl << endl;
}

void test7(){
    cout << "----- Problem 7: top k frequent elements -----" << endl;
    vector<int> numbers = {1,1,1,2,2,3};
    int k = 2;
    cout << "input:  "; printVector(numbers); cout << ", k=" << k << endl;
    vector<int> result = gachen7knumber(numbers, k);
    cout << "output: "; printVector(result); cout << endl;
    cout << "expect: [1, 2]" << endl << endl;
}

void test8(){
    cout << "----- Problem 8: merge k sorted arrays -----" << endl;
    vector<vector<int>> arrays = {{1,4,5},{1,3,4},{2,6}};
    cout << "input:  "; print2DVector(arrays); cout << endl;
    vector<int> result = gachen8karrays(arrays);
    cout << "output: "; printVector(result); cout << endl;
    cout << "expect: [1, 1, 2, 3, 4, 4, 5, 6]" << endl << endl;
}

void test9(){
    cout << "----- Problem 9: kth largest element -----" << endl;
    vector<int> numbers = {3,2,1,5,6,4};
    int k = 2;
    cout << "input:  "; printVector(numbers); cout << ", k=" << k << endl;
    int result = gachen9kthnumber(numbers, k);
    cout << "output: " << result << endl;
    cout << "expect: 5" << endl << endl;
}

void test10(){
    cout << "----- Problem 10: count inversions -----" << endl;
    vector<int> values = {2,4,1,3,5};
    cout << "input:  "; printVector(values); cout << endl;
    long long result = gachen10inversions(values);
    cout << "output: " << result << endl;
    cout << "expect: 3" << endl << endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}


