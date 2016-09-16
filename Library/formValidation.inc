<!-- #INCLUDE FILE="regularExpressions.inc" -->

<%
  //Function to validate usernames and passwords.
  function validateAccount(str,min,max)
  {
    try
    {
      var bolValAcct = false;
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          (hasLetters(str) == true || hasNumbers(str) == true)
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          && hasChar(str,"'") == false
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str," ") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
      
      if (bolValText == true && str.length >= min && str.length <= max)
      {
        bolValAcct = true;
      }
      else
      {
        bolValAcct = false;
      }
      
      return bolValAcct;  
    }
    catch(exception)
    {
      return false;
    }
  }

  //Function to validate email addresses.          
  function validateEmail(str)
  {
    try
    {
      var bolValEmail = false;
      var bolValText = false;
      var numAts = 0;
      var numPeriods = 0;
      
      //Validate characters in the string.      
      if (
          (hasLetters(str) == true || hasNumbers(str) == true)
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == true
          && hasChar(str,".") == true
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          || hasChar(str,"'") == true
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str," ") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }  
      
      //Count the number of '@' and '.' characters.
      for (var i = 0; i < str.length; i++)
      {
        if (str.charAt(i) == '@')
        {
          numAts++;
        }
        else if (str.charAt(i) == '.')
        {
          numPeriods++;
        }
      }
      
      if (bolValText == true && numAts == 1 && numPeriods >= 1)
      {
        //Check that there's an email name, a domain, and a domain name.
        var strEmailName = new String(strEmail.substring(0,strEmail.indexOf("@")));
        var strDomainName = new String(strEmail.substring((strEmail.indexOf("@") + 1),strEmail.lastIndexOf(".")));
        var strDomain = new String(strEmail.substring((strEmail.lastIndexOf(".")),strEmail.length));
        
        if (strEmailName.length >= 1 && strDomainName.length >= 1 && strDomain.length >= 2)
        {
          bolValEmail = true;
        }
        else
        {
          bolValEmail = false;
        }      
      }
      else
      {
        bolValEmail = false;
      }
                        
      return bolValEmail;
    }
    catch (exception)
    {
      return false;
    }
  }
  
  //Function to validate names, cities, states, countries, etc.
  function validateAlpha(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == true
          && hasNumbers(str) == false
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          || hasChar(str,"'") == true
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str,"_") == false          
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate full names.
  function validateFullName(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == true
          && hasNumbers(str) == false
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          && hasChar(str," ") == true
          || hasChar(str,"'") == true
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str,"_") == false          
         )
      { 
        //Ensure that a surname follows the space after the first name.
        var strFullName = new String(str);
        strFullName = strFullName.substring(strFullName.indexOf(" "),strFullName.length);
        
        if (strFullName.length > 1)
        {        
          bolValText = true; 
        }
        else
        {
          bolValText = false;
        }  
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate country codes.
  function validateCountry(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == true
          && hasNumbers(str) == false
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          && hasChar(str,"'") == false
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str," ") == false
          && hasChar(str,"-") == false
          && hasChar(str,"_") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate zip codes.
  function validateZip(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == false
          && hasNumbers(str) == true
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          && hasChar(str,")") == false
          && hasChar(str,"(") == false
          && hasChar(str,"+") == false
          && hasChar(str,"'") == false
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str," ") == false
          && hasChar(str,"_") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate phone numbers.
  function validatePhone(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == false
          && hasNumbers(str) == true
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          && hasChar(str,".") == false
          || hasChar(str,")") == true
          || hasChar(str,"(") == true
          || hasChar(str,"+") == true
          && hasChar(str,"'") == false
          && hasChar(str,",") == false
          && hasChar(str,"/") == false
          && hasChar(str,"_") == false
          || hasChar(str," ") == true
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate addresses.
  function validateAddress(str)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(str) == true
          || hasNumbers(str) == true
          && hasNoExtraneousChars(str) == true
          && hasNoInvalidChars(str) == true
          && hasChar(str,"@") == false
          || hasChar(str,".") == true
          || hasChar(str,")") == true
          || hasChar(str,"(") == true
          || hasChar(str,"+") == true
          || hasChar(str,"'") == true
          || hasChar(str,",") == true
          || hasChar(str,"/") == true
          || hasChar(str," ") == true
          && hasChar(str,"_") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate numbers.
  function validateNumbers(dbl)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(dbl) == false
          && hasNumbers(dbl) == true
          && hasNoExtraneousChars(dbl) == true
          && hasNoInvalidChars(dbl) == true
          && hasChar(dbl,"@") == false
          && hasChar(dbl,")") == false
          && hasChar(dbl,"(") == false
          && hasChar(dbl,"+") == false
          && hasChar(dbl,"'") == false
          && hasChar(dbl,",") == false
          && hasChar(dbl,"/") == false
          && hasChar(dbl," ") == false
          && hasChar(dbl,"_") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }    
  
    //Function to validate integers.
  function validatePosNumbers(dbl)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(dbl) == false
          && hasNumbers(dbl) == true
          && hasNoExtraneousChars(dbl) == true
          && hasNoInvalidChars(dbl) == true
          && hasChar(dbl,"@") == false
          && hasChar(dbl,".") == false
          && hasChar(dbl,")") == false
          && hasChar(dbl,"(") == false
          && hasChar(dbl,"+") == false
          && hasChar(dbl,"'") == false
          && hasChar(dbl,",") == false
          && hasChar(dbl,"/") == false
          && hasChar(dbl," ") == false
          && hasChar(dbl,"_") == false
          && hasChar(dbl,"-") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }    
  
  //Function to validate integers.
  function validateIntegers(dbl)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(dbl) == false
          && hasNumbers(dbl) == true
          && hasNoExtraneousChars(dbl) == true
          && hasNoInvalidChars(dbl) == true
          && hasChar(dbl,"@") == false
          && hasChar(dbl,".") == false
          && hasChar(dbl,")") == false
          && hasChar(dbl,"(") == false
          && hasChar(dbl,"+") == false
          && hasChar(dbl,"'") == false
          && hasChar(dbl,",") == false
          && hasChar(dbl,"/") == false
          && hasChar(dbl," ") == false
          && hasChar(dbl,"_") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }    
  
  //Function to validate positive integers.
  function validatePosIntegers(int)
  {
    try
    {
      var bolValText = false;
    
      //Validate characters in the string.      
      if (
          hasLetters(int) == false
          && hasNumbers(int) == true
          && hasNoExtraneousChars(int) == true
          && hasNoInvalidChars(int) == true
          && hasChar(int,"@") == false
          && hasChar(int,".") == false
          && hasChar(int,")") == false
          && hasChar(int,"(") == false
          && hasChar(int,"+") == false
          && hasChar(int,"'") == false
          && hasChar(int,",") == false
          && hasChar(int,"/") == false
          && hasChar(int," ") == false
          && hasChar(int,"_") == false
          && hasChar(int,"-") == false
         )
      { 
        bolValText = true; 
      }
      else
      { 
        bolValText = false; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }
  
  //Function to validate empty/unselected fields.
  function validateField(str,invalid)
  {
    try
    {
      var bolValText = false;
      var strVal = new String(str);
      var strInvalid = new String(invalid);
    
      //Validate non-empty string.      
      if (
          strVal.valueOf() == ""
          || strVal.valueOf() == strInvalid.valueOf()
          || strVal.valueOf() == "-------------------------"
          || strVal.valueOf() == "undefined"
         )
      { 
        bolValText = false; 
      }
      else
      { 
        bolValText = true; 
      }
            
      return bolValText;  
    }
    catch(exception)
    {
      return false;
    }
  }    
%>