var SpecialWord = "";
var SpecialUrl = "";
var SpecialLetter = 0;

function setWord(word)
{
  SpecialWord = word;
  return SpecialWord;
}

function setUrl(url)
{
  SpecialUrl = url;
  return SpecialUrl;
}

function getKey() 
{
  var eventChooser = event.keyCode;  
  var which = String.fromCharCode(eventChooser).toLowerCase();

  if (which == SpecialWord.charAt(SpecialLetter)) 
  {
    SpecialLetter++;
  
    if (SpecialLetter == SpecialWord.length) 
    {
      window.location = SpecialUrl;
    }  
  }
  else 
  {
    SpecialLetter = 0;
  }  
}

document.onkeypress = getKey;