class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)           //if money is less than children return -1
            return -1;
int count =0;
      money=money-children;          // distributing 1 dollar to each children 
        if(money<7)
            return 0;               // if after distributing the amount is less than 7 (8-1 dollar) then it could never be 
                                                    // able to make exact 8 dollars
        
           while(money>=7)
           {
               count =count +1;               
               money=money-7;             //first compeleting 8 dollars to one children then next children and so on..untill money is less than 8
                                                                         // or there is no children left    
               children=children-1;
               if(children==0)
                   break;
           }
        if (children==0 and money>0)     //if every children have 8 dollars and still money is remaining then give the rest of the money to last children
                                                // and decrease the count
            return count -1;
        
        if(children==1 and money==3)      //if one children is still remaining and the money remaining is 3 which will make 4 on to the last children
            return count-1;              //To  prevent this use one more children to avoid the 4 dollars on to the last one
        
   return count;
    }
};