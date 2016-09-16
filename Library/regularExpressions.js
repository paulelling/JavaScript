//General regular expressions.
  var reLetters = new RegExp("[A,a,B,b,C,c,D,d,E,e,F,f,G,g,H,h,I,i,J,j,K,k,L,l,M,m,N,n,O,o,P,p,Q,q,R,r,S,s,T,t,U,u,V,v,W,w,X,x,Y,y,Z,z]");
  var reNumbers = new RegExp("[0,1,2,3,4,5,6,7,8,9]");
  var reExtraneous = new RegExp("[`,¬,¦,!,\",£,$,€,%,&,*,=,{,},;,:,#,~,|,<,>,?]");
  
  //Function to check if a string has letters.  
  function hasLetters(str)
  {
    try
    {
      var bolText = false;
      
      if (reLetters.test(str) == true) 
      { bolText = true; }
      else
      { bolText = false; }
      
      return bolText;
    }
    catch (exception)
    {
      return false;
    }
  }
  
  //Function to check if a string has numbers
  function hasNumbers(str)
  {
    try
    {
      var bolText = false;
      
      if (reNumbers.test(str) == true) 
      { bolText = true; }
      else
      { bolText = false; }
      
      return bolText;
    }
    catch (exception)
    {
      return false;
    }
  }
  
  //Function to check that a string doesn't have extraneous characters.
  function hasNoExtraneousChars(str)
  {
    try
    {
      var bolValid = false;
    
      if (reExtraneous.test(str) == false)
      { bolValid = true; }
      else
      { bolValid = false; }
      
      return bolValid;      
    }
    catch (exception)
    {
      return false;
    }
  }
  
  //Function to check if a string has invalid characters.
  function hasNoInvalidChars(str)
  {
    try
    {
      var bolValid = false;
      
      var numInvalids = 0;
      for (var i = 0; i < str.length; i++)
      {
        if (str.charAt(i) == '[' ||
            str.charAt(i) == ']' ||
            str.charAt(i) == '^' ||
            str.charAt(i) == '\\'
           )
        {  
          numInvalids++;
        }
      }
  
      if (numInvalids == 0)
      { bolValid = true; }
      else
      { bolValid = false; }
      
      return bolValid;
    }
    catch (exception)
    {
      return false;
    }
  }
  
  //Function to check if a string has a particular character.
  function hasChar(str,char)
  {
    try
    {
      var bolChar = false;
      var reChar = new RegExp("[" + char + "]");
      
      if (reChar.test(str) == true)
      { bolChar = true; }
      else
      { bolChar = false; }
      
      return bolChar;
    }
    catch (exception)
    {
      return false;
    }
  }