class Solution {
public:
     bool vowel(char a){
          if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
          else return false;
     }
    long long countVowels(string word) {
int n=word.length();
long long int count=0;
    // take 1D array! 
        int arr[word.length()];
        for(int i=0;i<n;i++){
        arr[i]=0;
        }
        for(int i=0;i<n;i++){
           if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){ arr[i]=1; }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
if(i==j){
count+=arr[i];
    continue;
}
else
{
    if( vowel(word[j])){
        arr[i]=arr[i]+1;
        count+=arr[i];
    }
    else {
        arr[i]=arr[i];
        count+=arr[i];
    }
}
            }
        }
        return count;
    }
};
