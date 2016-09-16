// Function to round a number to a specified amount of places.
function roundNumber(number, places)
{
  var numLength = new Number(number.toString().length);
  var decimalPos = new Number(number.toString().lastIndexOf('.'));
 
  if (places > 0) 
  {
    if ((numLength - decimalPos) > (places + 1)) 
    {
       var Rounder = Math.pow(10, places);
       return Math.round(number * Rounder) / Rounder;
    }
    else return number;
  }
  else return Math.round(number);
} 

