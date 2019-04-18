package codejamP3;

import java.util.*;
import java.math.BigInteger;

public class P3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int t=input.nextInt();
	    for(int cnt=1; cnt<=t; cnt++)
	    {
	        int n=input.nextBigInteger(),L=input.nextInt();
	        String ans="";
	        BigInteger[] arr =new BigInteger[L];
	        BigInteger[] num =new BigInteger[L+1];
	        SortedSet<BigInteger> s= new TreeSet<BigInteger>();
	        Map<BigInteger,Character> m = new HashMap<BigInteger,Character>();
	        for(int i=0; i<L; i++)
	        {
	            arr[i]=input.nextBigInteger();
	        }
	        BigInteger g;
			int i,index;
	        for(i=0; i<L-1; i++)
	        {
	            if(arr[i].compareTo(arr[i+1])!=0)
	            {
	                g=arr[i].gcd(arr[i+1]);
	                num[i]=arr[i].divide(g);
	                num[i+1]=g;
	                num[i+2]=arr[i+1].divide(g);
	                s.add(num[i]);
	                s.add(num[i+1]);
	                s.add(num[i+2]);
	                break;
	            }
	        }
	        index=i;
	        while(i>0)
	        {
	            num[i-1]=arr[i-1].divide(num[i]);
	            s.add(num[i-1]);
	            i--;
	        }
	        i=index;
	        while(i<L)
	        {
	            num[i+1]=arr[i].divide(num[i]);
	            s.add(num[i+1]);
	            i++;
	        }
	        int c=0;
	        for(BigInteger x:s)
	        {
	            m.put(x,(char) ('A'+c));
	            c++;
	        }
	        for(i=0 ;i<=L; i++)
	        {
	            ans+=(m.get(num[i]));
	        }
	        System.out.printf("Case #%d: ",cnt);
	        System.out.println(ans);
	    }
	}
}
