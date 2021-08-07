function probChi( Chisqnorm,  N1) {

		var p = 0;
		var AM = 1.7E-38;
		var WU2P = 2.5066282746310005;
		var pr,z,SU;
		var J;
	 	if (Chisqnorm==0)
	 		return 1;

		var EC = Math.exp(-Chisqnorm/2);
		// IF ED<AM GOTO 1200
		switch(N1) {
			case 1:
			 z = Math.sqrt(Chisqnorm);
				pr = 1 - zProb(z);
				p = 2*pr;
				return p;
			case 2:
				p = EC;
			return p;
		}


		var CX = Math.sqrt(Chisqnorm);
		var ZC = 1.0/WU2P*EC;

		var IE,I1;
		var RD;
		if (N1%2 == 0) {
			IE = 1;
			SU = ZC;
			I1 = (N1-2)/2;
			RD =ZC;
		}
		else {
			IE = 0;
			SU = 0;
			I1 = (N1-1)/2;
			RD = ZC/CX;
		}
		if (RD>=AM && N1<=500) {
		//if ( N1<=500) {
				z = CX;
			    pr = 1 - zProb(z);

			    if (IE==1)
			    	 J = 2;
			    else
			    	J = 1;

			    for (var i=1;i<=I1;i++) {
			    	RD=RD*Chisqnorm/J;
			    	J += 2;
			    	SU += RD;
			    }

			    if (IE==1) {
			    	p = WU2P*SU;

			    }
			    else {
			    	p = 2*(pr + SU);

			    }


			}
			else {

				var z0= Math.pow(Chisqnorm/N1,0.333333333333333333)-1.0+2.0/(9.0*N1);
				z=z0*Math.sqrt(9.0*N1/2.0);
				p=1-zProb(z);

			}
			 return p;
	}
	
	
	function zProb (z){
				
				
			
	if (z<-7) {return 0.0;}
	if (z>7) {return 1.0;}


	if (z<0.0) {flag= true;}
	else
		{flag = false;}

	z = Math.abs(z);
	b=0.0;
	s=Math.sqrt(2)/3*z;
	HH=.5;
	for (var i=0;i<12;i++) {
		a = Math.exp(-HH*HH/9)*Math.sin(HH*s)/HH;
		b=b+a;
		HH=HH+1.0;
	}
	p= .5-b/Math.PI;
//p=b/Math.PI;
	if (!flag) {p=1.0-p;}
	return p;
}
// JavaScript Document