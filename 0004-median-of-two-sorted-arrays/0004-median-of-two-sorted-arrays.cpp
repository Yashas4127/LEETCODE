class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
  int n1=a.size();
  int n2=b.size();
  double ans; 
   vector<int> c;
    int i=0,j=0;
	 while(i<n1 && j<n2){
		  if(a[i]>b[j])
		  { 
			  c.push_back(b[j]);
				   j++;
		   } else{
			    c.push_back(a[i]);
				i++; 
		   } 
		
		     
			} while(i<n1)
			{ 
				c.push_back(a[i]); 
				i++;
			}
			 while(j<n2)
			{ 
				c.push_back(b[j]);
					j++;
				} 
				int n=n1+n2; 
				if(n%2==0)
				{
					ans=(c[n/2]+c[(n/2)-1])/2.0;
				} 
				else{
					ans=c[n/2]; 
				}
					return ans; 
}

    
};