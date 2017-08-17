import java.util.Calendar;
import java.text.SimpleDateFormat;
import java.util.Scanner;
import java.util.Date;

class D
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		Calendar cal= Calendar.getInstance();
		SimpleDateFormat sf=new SimpleDateFormat("dd/MM/yyyy");
		String day;
		String dat;
		int answer=0;
		Date date=null, initdate=null;
		int daysdiff;
		int initday=0;
		int curday=0;

		day=s.nextLine().trim();


		

		if(day.equals("Monday")) initday=2;
		else if(day.equals("Tuesday")) initday=3;
		else if(day.equals("Wednesday")) initday=4;
		else if(day.equals("Thursday")) initday=5;
		else if(day.equals("Friday")) initday=6;
		else if(day.equals("Saturday")) initday=0;
		else if(day.equals("Sunday")) initday=1;
		else 
		 	{
		 		System.out.print("Invalid Day");
				return;
		 	}
		
		dat=s.nextLine();
		try
		{
			sf.setLenient(false);
		 cal.setTime(sf.parse(dat));
		
		date = sf.parse(dat);
		initdate = sf.parse("01/01/0001");
		}catch(Exception e){System.out.print("Invalid Date");return;}
		
		daysdiff = getDifferenceDays(initdate, date);

		System.out.println(daysdiff);
		if(daysdiff%4==0) answer=1;
		else
		{
			curday=(daysdiff + initday+2 )%7;
			if(curday==0 || curday==1) answer=2;
			else
			{
				Calendar c = Calendar.getInstance();
				c.setTime(date);
				answer = c.get(Calendar.DAY_OF_YEAR)%51;
			}

		}
		System.out.print(answer);


	}


	public static int getDifferenceDays(Date d1, Date d2) 
	{
		int daysdiff=0;
		long diff = d2.getTime() - d1.getTime();
		long diffDays = diff / (24 * 60 * 60 * 1000)+1;
		 daysdiff = (int) diffDays;
		return daysdiff;
 	}

}