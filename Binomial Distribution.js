function calculate(v) {
	//disableAllInputs()
	var ll,ul
	if(whichRegion == v) {
	whichRegion = v
	//document.getElementById(radios[v]),checked = true
	  var  N= parseInt(document.getElementById("N").value)
	   var p= parseFloat(document.getElementById("p").value)
	  
	  if(! isNaN(N) && ! isNaN(p)) {
		if(N>0 && p>0 && p<1) {
			switch(whichRegion) {
			  case 1:
			  var theInput=document.getElementById("above")
			  theInput.disabled=false
				 ll= parseInt(theInput.value)
				
					  if(! isNaN(ll) && ll >=0)
						display(ll+1,N)
				break  
			  case 2:	
			  
				   ul= parseInt(document.getElementById("below").value)
					if(! isNaN(ul) && ul >=0)
						display(0,ul-1)
				break 	
			  case 3:
				 ll= parseInt(document.getElementById("ll").value)
				  ul= parseInt(document.getElementById("ul").value)
				
				if(! isNaN(ul) && ul >=0 && ! isNaN(ll) && ll>=0)
						if(ll>ul) {
						var t=ll
						ll=ul
						ul=t	
							
						}
						display(ll,ul)
				break
				
				 
		  }
		  
  
		}
	  }
	}
}

function display(ll, ul) {
	
	ctx.fillStyle = "black";
	var n = parseInt(document.getElementById("N").value)
	
	//var x = parseInt(document.getElementById("X").value)
	var p = parseFloat(document.getElementById("p").value)
	
	//var z = b(p,n,x)
	
	var numIntervals=n+1
	var probs= new Array(numIntervals)
	var maxProb=0
	
	for (var i=0;i<numIntervals;i++) {
		probs[i]=b(p,n,i)
		maxProb= Math.max(maxProb,probs[i])
		
	}
	
	var topProb=Math.ceil(100*maxProb)/100
	
	
	
	var labelInfo=intlabels(0,numIntervals,10)
	var stepSize=Math.max(labelInfo[0],1)
	if(numIntervals<20) stepSize=1
	var interWidth=Math.floor((w-leftMargin-rightMargin)/numIntervals)
	var xAxisY=h-bottomMargin
	
	var labelIncY=intlabels(0,topProb,10)[0]
	
	var numLabelsY=Math.ceil(topProb/labelIncY)+1
	var numYintervals=topProb/labelIncY
	var yValueMax = (numYintervals +1)*labelIncY
	
	var lty = new LT(0,yValueMax,xAxisY,topMargin+8)
	
	
	ctx.clearRect(0,0,w,h)
	ctx.fillStyle="#F4F4F4"
	ctx.fillRect(0,0,w,h)
	ctx.fillStyle="#000000"
	//ctx.fillRect(leftMargin,topMargin,w-leftMargin-rightMargin, h-bottomMargin-topMargin)
	ctx.beginPath()
	
	var x0=Math.round(interWidth/2)+leftMargin
	var xf=x0+interWidth*numIntervals-interWidth/2
	var yaxisX= x0-interWidth/2
	ctx.moveTo(x0-interWidth/2,xAxisY)
	ctx.lineTo(xf,xAxisY)
	ctx.textBaseline = "top";
	ctx.textAlign = "center"
	ctx.fillText("X",(x0-interWidth/2+xf)/2, xAxisY+25)
	
	for (var i=0;i<numIntervals;i+=stepSize) {
		var x1=x0+i*interWidth
		ctx.fillText(i,x1, xAxisY+2)	
	}
	
	
	var yValue=0
	ctx.textAlign = "right";
	 ctx.textBaseline = "middle";
	for (var i=0;i<numLabelsY;i++){
		var lab=Math.round(100*yValue)/100 + ""
		if(i==0) lab="0.00"
		
		else if(lab.length<4) lab +="0"
		
		lab +=" -"
		ctx.fillText(lab, yaxisX, lty.transform(yValue))
		yValue+=labelIncY
		
		
	}
	var pCumulative=0
	for(var i=0;i<=n;i++) {
		var xloc= interWidth*i+interWidth+yaxisX
		ctx.moveTo(xloc, xAxisY)
		ctx.lineTo(xloc, xAxisY+4)
	
	}
	
	
	
	
	ctx.moveTo(yaxisX,xAxisY)
	ctx.lineTo(yaxisX,lty.transform(yValue-labelIncY/2))
	ctx.fillText("Probability",yaxisX-5,topMargin)
	
	var bHeight=lty.transform(probs[0])
	//ctx.fillRect(leftMargin,bHeight, interWidth, bHeight-xAxisY)
	//alert(bHeight + " " + probs[0])
	var left= leftMargin
	ctx.fillStyle = "blue";
	for (var i=0;i<numIntervals;i++) {
		
		var bHeight=lty.transform(probs[i])
		
			if(i>=ll && i <= ul) {
				ctx.fillStyle = "red"
				pCumulative+=probs[i]
			}
			else {
				
				ctx.fillStyle = "blue"
			}
		
		ctx.fillRect(left+4,bHeight,interWidth-8,xAxisY-bHeight)
		left+=interWidth
	}
	ctx.stroke()
	pCumulative=Math.round(10000*pCumulative)/10000
	document.getElementById("results").innerHTML="<b>Probability = " + pCumulative + "</b>"
}
	function nper(n, x) {
		var n1 = n+1;
		var r = 1.0;
		var xx =  Math.min(x,n-x);
		for (var i = 1; i< xx+1; i++) {
			r = r *  (n1-i);
			r = r/ i;
		}
		return r;
		
	}
	function b (p, n, x){
			var px = Math.pow(p, x) * Math.pow((1.0-p),(n-x));
			return nper(n,x)* px;
	}
	
	function intlabels(y1,y2,n) {
	/**
	   y1: Min
	   y2: max 
	   n: # of prefered labels
	   
	   return the label step size, the first label value and the last label value.
	 */
	 
	var R = new Array(3);
	var diff = y2-y1;
	var x = intervals(diff,n);
	var adj=0;
	R[0]=x;
	R[1] = Math.floor((y1-adj)/x)*x;
	R[2] = Math.ceil((y2+adj)/x)*x;
	return R;
}

function intervals(diff,NumCats){

	var T = new Array(4);
	var A = new Array(4);
	var t3 =  Math.pow(10,(Math.floor(Math.log(diff) *.4342945)));
	T[3] = t3;
	T[2] = t3/2;
	T[1] = t3/5;
	T[0]= t3/10;
	for (var i = 0;i<4;i++) {
		A[i] =  (Math.floor(diff/T[i])+1);
	}
	
	var D =  Math.abs(NumCats-A[0]);
	var IN =0;
	for (var i=1;i<4;i++) {
		if ((A[i]<=25) && (A[i] > 2)) {
			var X =  (Math.abs(NumCats-A[i]));
			if (X<D) {
				D=X;
				IN=i;
			}
		}

	}
		
	
	return T[IN];	
}

LT = function(x0,xf,y0,yf) {
	this.b = (yf-y0)/(xf-x0);          //slope
	this.A = (yf+y0)/2- this.b * (xf+x0)/2; //intercept
	
}
LT.prototype.transform = function (X) {
	
	return this.b*X+this.A;
}


LT.prototype.transformArray = function (X) {
		var N = X.length;
		var R = new Array(N);
		for (var i = 0; i< N; i++) {
			R[i] = this.b*X[i]+this.A;
		}
		return R;
}