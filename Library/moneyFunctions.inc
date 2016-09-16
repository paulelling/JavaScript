<%
  // Function to calculate tax.
  function calcTax(money,tax)
  {
    return money * tax;
  } 


  // Function to show last zero.
  function showZero(fltNum)
  {
    var strNum = new String(fltNum);
    var strDec = "";
    var strReturn = "";
    var numDec = 0;      
  
    for (var i = 0; i < strNum.length; i++)
    {
      if (strNum.charAt(i) == '.')
      {
        numDec++;
      }
    }
        
    if (numDec == 1)
    {
      strDec = strNum.substring(strNum.lastIndexOf('.'),strNum.length);
    
      if (strDec.length == 2)
      {
        strNum = strNum + "0";
      }  
    
      strReturn = strNum;
    }
    else
    {
      strReturn = strNum + ".00";
    }
        
    return strReturn;
  }
%>