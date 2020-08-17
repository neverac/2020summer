import java.util.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main 
{
	static Scanner cin=new Scanner(System.in);
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		
		
			String s1="bubble";
			String s2="tapioka";
			String s=cin.nextLine();
			String arr[]=s.split(" ");
			List<String> list=new ArrayList<String>();
			for(int i=0;i<arr.length;i++)
			{
				if(arr[i].equals(s1)||arr[i].equals(s2))
				{
					continue;
				}
				else
				{
					list.add(arr[i]);
				}
			}
			if(list.size()==0)
			{
				System.out.println("nothing");
			}
			else
			{
				for(int i=0;i<list.size();i++)
				{
					System.out.print(list.get(i)+" ");
				}
				System.out.println();
			}
		
	}
}