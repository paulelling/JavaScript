/**
 ** Validate input on the following criteria
 **     1.  Required values entered
 **     2.  Data type
 **     3.  Data length
**/
function ValidateInput(pEmplID, pLocation, pEmplIDLength, pLocationLength)
{
    var bInputValid = true;
    var sEmplID = pEmplID;
    var sLocation = pLocation;    
    var lEmplIDLength = pEmplIDLength;
    var iLocationLength = pLocationLength;
    var sMessage = "";
    var bFunction;
    var iArrayIndex = 0;
    
    var aFunctions = new Array(5);
    aFunctions[0] = HasValue(sEmplID);
    aFunctions[1] = HasValue(sLocation);
    aFunctions[2] = IsNumeric(sEmplID);
    aFunctions[3] = IsValidLength(sEmplID, lEmplIDLength);
    aFunctions[4] = IsValidLength(sLocation, iLocationLength);
    
    var aMessages = new Array(5);
    aMessages[0] = "Employee ID is required.";
    aMessages[1] = "Location is required.";
    aMessages[2] = "Employee ID must be numeric.";
    aMessages[3] = "Employee ID must be " + lEmplIDLength + " characters or less.";
    aMessages[4] = "Location must be " + iLocationLength + " characters or less.";

    for (iArrayIndex = 0; iArrayIndex < (aFunctions.length - 1); iArrayIndex++)
    {
        if (bInputValid)
        {
            bFunction = aFunctions[iArrayIndex];
            sMessage = aMessages[iArrayIndex];
            bInputValid = ValidateData(bFunction, sMessage);
        }
    }
    
    return bInputValid;
}
