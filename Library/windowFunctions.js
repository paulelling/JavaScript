// Variables to set a popup window's coordinates.
var intPopLeft = (screen.width - 350)/2;
var intPopTop = (screen.height - 200)/2;


// Function to open a window with a different URL.
function openWindow(url,width,height,toolbar,menubar,location,status,scrollbars,resizable)
{ 
  self.name = "mainWindow";
  window.open(url,"newWindow","toolbar=" + toolbar + ",menubar=" + menubar 
    + ",location=" + location + ",top=" + intPopTop + ",left=" + intPopLeft 
    + ",width=" + width + ",height=" + height + ",status=" + status + ",scrollbars="
    + scrollbars + ",resizable=" + resizable); 
}


// Function to open a window with a message.
function doPopupMsg(msg,width,height)
{
  var objWin = window.open("","newWindow","toolbar=no,menubar=no,location=no,width=" + width + ",height=" + height + ",status=no,scrollbars=no,resizable=yes");
  objWin.document.write(msg);
}


// Function to open a window with a message.
function doPopupMsg2(msg,width,height)
{
  var objWin = window.open("","newWindow","toolbar=no,menubar=no,location=no,width=" + width + ",height=" + height + ",status=no,scrollbars=no,resizable=yes");
  document.write();
  objWin.document.write(msg);
}


