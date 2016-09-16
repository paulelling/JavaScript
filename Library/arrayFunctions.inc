<%
  // Function to return an array's dimension.
  function getDimension(strArray,delimiter)
  {
    var numDimensions = 1;
    
    for (var i = 0; i < strArray.length; i++)
    {
      if (strArray.charAt(i) == delimiter)
      {
        numDimensions++;
      }
    }
    
    return numDimensions;
  }
  
  
  // Function to fill an array with values.
  function doFillArray(strArray,delimiter,dimension)
  {
    var arrArray = new Array(dimension);
    var numIndex = 0;
  
    for (var k = 0; k < strArray.length; k++)
    {
      if (strArray.charAt(k) != delimiter)
      {
        if (arrArray[numIndex] == null)
        {
          arrArray[numIndex] = "";
        }
        
        if (strArray.charAt(k) == "'")
        {
          arrArray[numIndex] += "'";
        }
        
        arrArray[numIndex] += strArray.charAt(k);
      }
      else
      {
        numIndex++;
      }
    }
    
    return arrArray;
  }

%>