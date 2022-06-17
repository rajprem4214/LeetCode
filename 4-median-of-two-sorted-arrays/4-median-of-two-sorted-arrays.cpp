class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    
vector<int>num(nums1.size()+nums2.size());
int i=0,k=0,j=0;
while(i<nums1.size() && j<nums2.size())
{
if(nums1[i]<nums2[j])
{
num[k++]=nums1[i++];
}
else
{
num[k++]=nums2[j++];
}
}
while(i<nums1.size())
{
num[k++]=nums1[i++];
}
while(j<nums2.size())
{
num[k++]=nums2[j++];
}
int mid=(nums1.size()+nums2.size())/2;
double median;
if((nums1.size()+nums2.size())%2==0)
{
median=(num[mid]+num[mid-1])/2.0;
}
else
{
median=num[mid];
}
return median;
}
};