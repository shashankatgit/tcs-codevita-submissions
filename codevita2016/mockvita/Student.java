import java.util.*;

public class Student {
    
    public static void main (String[] args){
        Scanner d = new Scanner(System.in);
        
            try{          
                    double amount=0.0;       
                    String P = d.next().trim();
                    String R = d.next().trim();
                    String time = d.next().trim();
                    double p = Double.parseDouble(P);
                    
                    double r = Double.parseDouble(R);
                    
                    int t = Integer.parseInt(time);

                    if(p<=0 || r<0)
                        {
                            System.out.print("Invalid Input");
                            return;
                        }

                    for(int i=0;i<t;i++){
                        amount += p + ((amount+p)*r)/1200.0;
                    }

                    
                    long ans= Math.round(amount);
                    System.out.println("Final_Amount " + ans);
                
                }
              catch(NumberFormatException e)
              {
                    System.out.print("Invalid Input");
                    return;
                }
        
    }
}