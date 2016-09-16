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
        bolValEmail = true;         
      }
      else
      {
        bolValEmail = false;
      }
                     
      return bolValEmail;
    }
    catch (exception)
    {
      return exception.toString();
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
          && hasChar(str,"_") == false
          && hasChar(str,"-") == false
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
  function validatePosIntegers(dbl)
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