// Function to clear form fields.
function doReset(formName)
{
  document.forms[formName].reset();  
}


// Function to copy a drop-down option's text to an input box.
function doSelectText(formName, copyItem, pasteItem)
{
  var si =  document.forms[formName].item(copyItem).selectedIndex;
  var fname = document.forms[formName].item(copyItem).options[si].innerText;
  document.forms[formName].item(pasteItem).value = fname;    
}


// Function to copy a drop-down option's text to a any form's input box.
function doSelectText2(formName, copyItem, formName2, pasteItem)
{
  var si =  document.forms[formName].item(copyItem).selectedIndex;
  var fname = document.forms[formName].item(copyItem).options[si].innerText;
  document.forms[formName2].item(pasteItem).value = fname;    
}


// Function to copy a drop-down option's value to any form's input box.
function doSelectValue(formName, copyItem, formName2, pasteItem)
{
  var si =  document.forms[formName].item(copyItem).selectedIndex;
  var fname = document.forms[formName].item(copyItem).options[si].value;
  document.forms[formName2].item(pasteItem).value = fname;    
}    


// Function to copy a drop-down option's text to another drop-down option's text.
function doCopyText(formName, copyItem, pasteItem)
{
  var si =  document.forms[formName].item(copyItem).selectedIndex;
  var fname = document.forms[formName].item(copyItem).options[si].innerText;
  var fvalue = document.forms[formName].item(copyItem).options[si].value;
  
  var si2 = document.forms[formName].item(pasteItem).selectedIndex;
  document.forms[formName].item(pasteItem).options[si2].innerText = fname;
  document.forms[formName].item(pasteItem).options[si2].value = fvalue;
}