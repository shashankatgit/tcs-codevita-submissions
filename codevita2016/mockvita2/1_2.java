import java.util.Scanner;


class A
{
	public static void main(String args[])
	{
		Scanner s= new Scanner(System.in);
		int lines;
		String line;
		lines = Integer.parseInt(s.nextLine());
		String names[] = new String[2];
		int state=0;
		int turn=0;
		int answer=0;
		boolean isNameSet = false;
		int points[]=new int[2];
		points[0]=points[1]=0;


		while(lines--!=0)
		{
			line = s.nextLine();
			String parts[] = new String[3];
			String subparts[];

			try
			{

				parts = line.split(" ");
			

				if(state==0)
				{
					if(parts[0].equals("A") || (isNameSet && (parts[0].equals(names[turn])))) {throw new Exception();}

					names[turn]=parts[0];
					subparts = parts[1].split(",");
					//System.out.println(parts[1]);
					// if(!subparts[0].matches("\\d+") || !subparts[1].matches("\\d+"))
					// {
					// 	System.out.println("Invalid Input");
					// 	return;
					// }
					System.out.print(names[turn]+"'s question is: "+subparts[0]);

					for(int i=0;i<subparts.length-1;i++)
						System.out.print(","+subparts[i+1]);
					System.out.print("\n");
					int lcm = findLCM(Integer.parseInt(subparts[0]),Integer.parseInt(subparts[1]));
					for(int i=0;i<subparts.length-2;i++)
					{
						lcm = findLCM(lcm,Integer.parseInt(subparts[i+2]));
					}
					answer = lcm;

				}

				else if(state==1)
				{
					turn++;
					turn%=2;
					if(!parts[0].equals("A") || (isNameSet && (parts[1].equals(names[turn])))) {throw new Exception();}
					names[turn] = parts[1];

					if(parts[2].equals("PASS"))
					{
						System.out.println("Question is PASSed");
						System.out.println("Answer is: "+answer);
					}

					else
					{
						if(Integer.parseInt(parts[2]) == answer)
						{
							System.out.println("Correct Answer");
							points[turn]+=10;
						}
						else
							System.out.println("Wrong Answer");
					}

					System.out.println(names[turn]+": "+points[turn]+"points");

				}

				if(turn==2) isNameSet=true;
			}
			catch(Exception e){System.out.println("Invalid Input"); return;}
			state++;
			state=state%2;
		}

		System.out.println("Total Points:");
		System.out.println(names[0]+": "+points[0]+"points");
		System.out.println(names[1]+": "+points[1]+"points");
		System.out.print("Game Result: ");
		if(points[0]>points[1])
			System.out.print(names[0]+" is winner");
		if(points[1]>points[0])
			System.out.print(names[1]+" is winner");
		else
			System.out.print("Draw");



	}

	// static int findLCM(int a,int b)
	// {
	//     int tmpx;
	//     int tmpy;
	//     if(a<b)
	//     {
	//         tmpx=a;
	//          tmpy=b;   
	//     }
	//     else
	//     {
	//          tmpx=b;
	//          tmpy=a;   
	//     }
	//     int i=1;
	//     while(true)
	//     {

	//         int tmpx1=tmpx*i;
	//         int tmpy1=tmpy*i;
	//         for(int j=1;j<=i;j++)
	//         {
	//         if(tmpx1==tmpy*j)
	//         {
	//             return tmpx1;
	//         }
	//         }

	//         i++;
	//     }
	// }

	public static int calcGCD(int a, int b)
	{
	    if (a<b) return calcGCD(b,a);
	    if (a%b==0) return b;
	    else return calcGCD(a, a%b);
	}


	public static int findLCM(int a, int b)
	{
	    return ((a*b)/calcGCD(a,b));
	} 
}