// Function to redirect to a specified URL.
function doRedirect(url)
{ 
  parent.location.href = url; 
}


// Function to navigate to a previous page.
function goBack(num)
{
  parent.history.go(num);
}


// Function to navigate from a drop-down select box.
function doSelectGo(formName,selectName)
{
  var objIndex = document.forms[formName].item(selectName).selectedIndex
  parent.location.href = (document.forms[formName].item(selectName).options[objIndex].value);
}