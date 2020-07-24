import java.util.*;
import java.math.BigInteger;
public class Main 
{
	static Scanner cin=new Scanner(System.in);
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		BigInteger n;
		String s;
		s=cin.next();
		n=new BigInteger(s);
		BigInteger a=new BigInteger("4");
		if(n.mod(a).toString().equals("0"))
		{
			System.out.println(4);
		}
		else
		{
			System.out.println(0);
		}
	}
}