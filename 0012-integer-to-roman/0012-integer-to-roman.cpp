class Solution {
public:
    string intToRoman(int num) {
        int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
            string sign[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
            string sb;
           
            for(int i=0; i<13 && num>0; i++){
                    while(number[i]<=num){
                            num=num-number[i];
                            sb.append(sign[i]);
                    }
            }
        return sb;
    }
};