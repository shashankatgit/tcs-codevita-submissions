import java.util.*;

public class Student {
    
    public static void main (String[] args){
        Scanner d= new Scanner(System.in);
        try{
                      
                double amount=0.0;       
                double p = Double.parseDouble(d.next().trim());
                p= (double)Math.round(p * 100000000000d) / 100000000000d;
                double r = Double.parseDouble(d.next().trim());
                r= (double)Math.round(r * 100000000000d) / 100000000000d;
                int t = Integer.parseInt(d.next().trim());
                if(t<=0 || p<=0|| r<=0)
                    throw new Exception();
                for(int i=0;i<t;i++){
                    amount += p + ((amount+p)*r)/1200.0;
                }
                long ans= Math.round(amount);
                System.out.println(ans);
                
             
        }catch(Exception e){
            System.out.println("Invalid Input");
        }
    }
}