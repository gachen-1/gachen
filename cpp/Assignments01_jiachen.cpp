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
        return { };  //define a two dimensional vector gachen1 to store gaps
     
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




//problem2
//count:
vector<int> gachen2count(vector<int>& threenumbers){
    int a=0, b=0, c=0;//count the number(0,1,2) in threenumbers
    for (int i=0; i<threenumbers.size(); i++){
        if (threenumbers[i] == 0) //use a,b,c as three containers to store
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
      int left=0,current=0,right=threenumbers.size()-1;//use three pointers to store the position(0,1,2)
      while(current<=right){
          if (threenumbers[current]==0){
               swap(threenumbers[left],threenumbers[current]);
               left++;
               current++;
          }//if the current is 0, swap the current with left pointer, and move left and current move a step to right
          else if (threenumbers[current]==2){
               swap(threenumbers[current],threenumbers[right]);
               right--;
          }//same as the above
          else{
               current++;
          }
      }
      return threenumbers;
}




//problem3
string gachen3biggest(vector<int>& numbers){
     if (numbers.empty())
        return" ";
    
    vector<string> str;//store the numbers in string format
    for (int i=0; i<numbers.size(); i++){
       str.push_back(to_string(numbers[i]));//put the numbers into str 
    }
    sort(str.begin(),str.end(),[](const string& a, const string& b) {
        return a + b > b + a;//sort in internal order
    });
    string result;
    for (int i=0; i<str.size(); i++){
        result=result+str[i];///put the numbers in str into result
         return result;
    }
}



//problem4
vector<vector<string>> gachen4Anagrams(vector<string>& words){
       unordered_map<string,vector<string>> map;
       if (words.empty())
            return {};
       
       for (int i=0; i<words.size(); i++){
           string key=words[i];//first, sort the words in letters, then put the sorted words into key
           sort(key.begin(), key.end());
           map[key].push_back(words[i]);
       }
        vector<vector<string>> result;//store the words with the same key into result
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }
    return result;
}
     




//problem5
bool gachen5meetings(vector<vector<int>>& meetings){
        if (meetings.empty())
            return true;//
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];//sort the meetings in order of start time
        });
        for (int i=0; i<meetings.size()-1; i++){
            if (meetings[i][1]>meetings[i+1][0]){
                return false;//compare the end of time with the start of time
            }
        }
        return true;
 }


//problem6
//sort
vector<vector<int>> gachen6sort(vector<vector<int>> &points, int k){
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] < b[0]*b[0];
        });//sort the points in order to seek the distance from the zero point
        vector<vector<int>> result;
        for (int i=0; i<=k; i++){
            result.push_back(points[i]);
        }
        return result;
    }


//heap
vector<vector<int>> gachen6heap(vector<vector<int>> &points, int k){
        priority_queue<pair<int,int>> maxHeap;
//use the maxHeap to store the distance and index of points
    for (int i = 0; i < points.size(); ++i) {
        int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];//calculate the distance from the zero point
        if (maxHeap.size() < k) {
            maxHeap.push({distance, i});//if the size of maxHeap is smaller than k, push the distance and index of this point into maxHeap
        } else if (distance < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({distance, i});
        }//put the distance and index of this point into maxHeap 
    }

    vector<vector<int>> result;
    for (int i = 0; i < k; ++i) {
        int index = maxHeap.top().second;//get the index of the point with the largest distance
        result.push_back(points[index]);
        maxHeap.pop();
    }//put the smallest distance points into result
    return result;
}






//problem7
vector<int> gachen7knumber(vector<int>& numbers, int k){
         unordered_map<int,int> frequency;
         for (int i=0; i<numbers.size(); i++){
             frequency[numbers[i]]++;//record the frequency of each number in numbers
         }
         vector<pair<int,int>> pairs(frequency.begin(), frequency.end());//put the frequency into pairs
         sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) {
                return  a.second > b.second;//sort the pairs in order of frequency
            }
            return a.first < b.first;//if the frequency is the same, sort the pairs in order of number
        });
         
         vector<int> result;
         for(int i=0; i<k; i++){
             result.push_back(pairs[i].first);
         }//put the most frequent k numbers into result
         return result;
    }
         



//problem8
vector<int> gachen8karrays(vector<vector<int>>& arrays){
        using x=tuple<int, int, int>;
        priority_queue<x, vector<x>, greater<x>> minHeap; //use the minHeap to store the value, array index, and element index
        for (int i=0; i<arrays.size(); i++){
            if (!arrays[i].empty()){
                minHeap.push({arrays[i][0], i, 0});
            }//put the first element of each array into minHeap
       }
        
        vector<int> result;
        while (!minHeap.empty()){
            auto[value, array, elements] = minHeap.top();//get the value, array index, and element index in smallest element in minHeap
            minHeap.pop();
            result.push_back(value);
            
            if (elements + 1 < arrays[array].size()){
                minHeap.push({arrays[array][elements + 1], array, elements + 1});
            }//if the next element in the same array exists, push it into minHeap
        }
        return result;
    }


//problem9
int gachen9kthnumber(vector<int>& numbers,int k){
        priority_queue<int, vector<int>, greater<int>> minHeap;//use the minHeap to store the numbers
        for (int i=0; i<numbers.size(); i++){
            minHeap.push(numbers[i]);//push the numbers into minHeap
            if (minHeap.size()>k){
                minHeap.pop();
            }
        }//if the size of minHeap is larger than k, pop the smallest element in minHeap
        return minHeap.top();
    }





    
//problem10
long long gachen10merge(vector<int>& values, vector<int>& temp, int left, int mid, int right){
    int i=left, j=mid+1, k=left;
    long long count=0;//count the number of inversions
    while (i<=mid && j<=right){
        if (values[i]<=values[j]){
            temp[k]=values[i];
            i++;//put the left value into temp
        }
        else{
            temp[k]=values[j];
            j++;
            count=count+(mid-i+1);
        }
            k++;//put the right value into temp and count the number of inversions
    }
    while (i<=mid){
        temp[k]=values[i];
        i++;
        k++;
    }//put the left value into temp
    while (j<=right){
        temp[k]=values[j];
        j++;
        k++;
    }//put the right value into temp
    for (int a=left; a<=right; a++){
        values[a]=temp[a];
    }
    return count;
}//merge the left and right values into temp and count the number of inversions

long long gachen10sort(vector<int>& values, vector<int>& temp, int left, int right){
    if (left>=right)
        return 0;

    int mid=(left+right)/2;
    long long count=gachen10sort(values,temp,left,mid);
    count=count+gachen10sort(values,temp,mid+1,right);
    count=count+gachen10merge(values,temp,left,mid,right);
    return count;
}//sort the left and right values and count the number of inversions

long long gachen10inversions(vector<int>& values){
    if (values.empty())
        return 0;

    vector<int> temp(values.size());
    return gachen10sort(values,temp,0,values.size()-1);
}//count the number of inversions in values




//print functions
void printVector(const vector<int>& gachen){
    cout << "[";//print the vector 
    for (int i=0; i<gachen.size(); i++){
        cout << gachen[i];
        if (i+1<gachen.size()) cout << ", ";
    }
    cout << "]";
}//

void print2DVector(const vector<vector<int>>& gachen){
    cout << "[";
    for (int i=0; i<gachen.size(); i++){
        printVector(gachen[i]);
        if (i+1<gachen.size()) cout << ", ";
    }
    cout << "]";
}

void printStringVector(const vector<string>& gachen){
    cout << "[";
    for (int i=0; i<gachen.size(); i++){
        cout << gachen[i];
        if (i+1<gachen.size()) cout << ", ";
    }
    cout << "]";
}

void print2DStringVector(const vector<vector<string>>& gachen){
    cout << "[";
    for (int i=0; i<gachen.size(); i++){
        printStringVector(gachen[i]);
        if (i+1<gachen.size()) cout << ", ";
    }
    cout << "]";
}


//test functions
void test1(){
    cout <<"Problem1"<< endl;//put the gaps into gachen1 to merge the overlapping intervals
    vector<vector<int>> gaps = {{1,3},{2,6},{8,10},{15,18}};
    cout << "input:  "; print2DVector(gaps); cout << endl;//print the input gaps
    vector<vector<int>> result = gachen1(gaps);//put the gaps into gachen1 to merge the overlapping intervals
    cout << "output: "; print2DVector(result); cout << endl;
    cout << "expect: [[1, 6], [8, 10], [15, 18]]" << endl << endl;
}

void test2(){
    cout <<"Problem2"<< endl;
    vector<int> arr1 = {2,0,2,1,1,0};
    vector<int> arr2 = arr1; 
    cout << "input:"; printVector(arr1); cout << endl;

    vector<int> countResult = gachen2count(arr1);
    cout << "count sort output:"; printVector(countResult); cout << endl;

    vector<int> dutchResult = gachen2Dutchflag(arr2);
    cout << "dutch flag output:"; printVector(dutchResult); cout << endl;
    cout << "expect (sorted 0/1/2):[0, 0, 1, 1, 2, 2]" << endl << endl;
}

void test3(){
    cout <<"Problem3"<< endl;
    vector<int> numbers = {3,30,34,5,9};
    cout << "input:"; printVector(numbers); cout << endl;
    string result = gachen3biggest(numbers);
    cout << "output:" << result << endl;
    cout << "expect: 9534330" << endl << endl;
}

void test4(){
    cout <<"Problem4"<< endl;
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    cout << "input:"; printStringVector(words); cout << endl;
    vector<vector<string>> result = gachen4Anagrams(words);
    cout << "output:"; print2DStringVector(result); cout << endl;
    cout << "expect groups:[eat,tea,ate], [tan,nat], [bat]" << endl << endl;
}

void test5(){
    cout << "Problem5"<< endl;
    vector<vector<int>> overlapping = {{0,30},{5,10},{15,20}};
    vector<vector<int>> nonOverlapping = {{7,10},{2,4}};
    cout << "input(overlap):"; print2DVector(overlapping); cout << endl;
    cout << "output: " << (gachen5meetings(overlapping) ? "true" : "false") << " (expect: false)" << endl;
    cout << "input(no overlap):"; print2DVector(nonOverlapping); cout << endl;
    cout << "output: " << (gachen5meetings(nonOverlapping) ? "true" : "false") << " (expect: true)" << endl << endl;
}

void test6(){
    cout << "Problem6"<< endl;
    vector<vector<int>> points1 = {{1,3},{-2,2},{2,-2},{5,8}};
    vector<vector<int>> points2 = points1;
    int k = 2;
    cout << "input:"; print2DVector(points1); cout << ", k=" << k << endl;

    vector<vector<int>> sortResult = gachen6sort(points1, k);
    cout << "sort version output:"; print2DVector(sortResult); cout << endl;

    vector<vector<int>> heapResult = gachen6heap(points2, k);
    cout << "heap version output: "; print2DVector(heapResult); cout << endl << endl;
}

void test7(){
    cout << "Problem7"<< endl;
    vector<int> numbers = {1,1,1,2,2,3};
    int k = 2;
    cout << "input:"; printVector(numbers); cout << ", k=" << k << endl;
    vector<int> result = gachen7knumber(numbers, k);
    cout << "output: "; printVector(result); cout << endl;
    cout << "expect: [1, 2]" << endl << endl;
}

void test8(){
    cout << "Problem8"<< endl;
    vector<vector<int>> arrays = {{1,4,5},{1,3,4},{2,6}};
    cout << "input:"; print2DVector(arrays); cout << endl;
    vector<int> result = gachen8karrays(arrays);
    cout << "output: "; printVector(result); cout << endl;
    cout << "expect: [1, 1, 2, 3, 4, 4, 5, 6]" << endl << endl;
}

void test9(){
    cout << "Problem9"<< endl;
    vector<int> numbers = {3,2,1,5,6,4};
    int k = 2;
    cout << "input:"; printVector(numbers); cout << ", k=" << k << endl;
    int result = gachen9kthnumber(numbers, k);
    cout << "output: " << result << endl;
    cout << "expect: 5" << endl << endl;
}

void test10(){
    cout << "Problem10"<< endl;
    vector<int> values = {2,4,1,3,5};
    cout << "input:"; printVector(values); cout << endl;
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


