	/** 
	 * calculate the F probability of double fr with degree of freedom df1=dn and df2=dd 
	 */ 
	function probF( fr,  dn,  dd) {

		var f = fr;
		var a = dn;
		var b = dd;
		var iv=0;
		var fp;
		if (Math.floor(a/2) * 2 == a) {
			fp = L401(a,f,b,iv);//even numerator df
			//return fp;
		}

		else if (Math.floor(b/2) * 2 != b) {
			fp = L504(a,f,b,iv); //odd numerator df and odd denomiator df
			//return fp;
		}
		else {  //odd numerator df and even denomiator df, do inverse of L401
			f=1/f;
			a=dd;
			b=dn;
			iv=1;
			fp = L401(a,f,b,iv);
		
			//return fp;
		}
		fp = Math.max(fp,0.0);
		return fp;
}

/**
 * The probability of T, easy to convert to F distribution with numerator degree of
 * freedom = 1
 */
function probT( t,  df) {
	var F = t*t;
	return probF(F,1,df);
}

/**
 * detail of F probability calculation with odd numerator degree of freedom
 */	
function L504( a, f, b, iv) {
	var q = a*f/(a*f+b);
	var sa = Math.sqrt(q);
	var sl = Math.log(sa);
	var ca = Math.sqrt(1-q);
	var cl = Math.log(ca);
	var al = Math.atan(sa/Math.sqrt(-sa*sa+1));
	var fp = 1-2*al/Math.PI;
	var r=0;
	var c;
	var n;
	if (b!=1) {
		c = Math.log(2*sa/Math.PI);
		fp-=Math.exp(c+cl);
		if (b!=3) {
			 n =  Math.floor((b-3)/2);
			for (var i=1;i<=n;i++) {
				var x = (2*i+1);
				r+=Math.log((x-1)/x);
				var rr=r+cl*x+c;
				if (rr>-78.4) {
					fp-=Math.exp(rr);
				}
			}
		}
	}
	
	if (a!=1) {
		 c = r;
		
		if (b>1) {
			c+=Math.log(b-1);
		}
		
		c+=Math.log(2/Math.PI) + sl + cl*b;
		
		if (c>-78.4) {fp+=Math.exp(c);}
		
		if (a!=3) {
			 n =  Math.floor((a-3)/2);
			r=0;
			for (var i=1;i<=n;i++) {
				var x=  (i*2+1);
				r+=Math.log((b+x-2)/x);
				var rr=r+sl*(x-1)+c;
				if (rr>-78.4) {fp+=Math.exp(rr);}
			}
		}
	}	
	return fp;
	
}

/**
 * detail of F probability calculation with even numerator degree of freedom
 */
function  L401( a, f, b, iv) {

			var q = a*f/(a*f+b);
			var ql=Math.log(q);
			var fp=0;
			var c = Math.log(1-q)*b/2;
			var n;
			if (c>-78.4) {
				fp = Math.exp(c);
			}
			
			if (a != 2) {
			 n =  Math.floor(a/2-1);
				var r=0;
				for (var i=1;i<=n;i++) {
					var x= (2*i);
					r+=Math.log(b+x-2)-Math.log(x) + ql;
					if (r+c> -78.4) {
						fp+=Math.exp(r+c);
					}
				 }
				}
				
				if (iv==1) {
					fp = 1-fp;
				}

			return fp;
		}// JavaScript Document