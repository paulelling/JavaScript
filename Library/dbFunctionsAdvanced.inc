<%
  /*********************************************************
   ** NOTE: arrayFunctions.inc must be included in the ASP before this include file.
   ** NOTE: dbFunctions.inc must also be included in the ASP before this include file.
   **
   ** Database Operation:
   ** 1. Open connection.
   ** 2. Perform query.
   ** 3. Return results.
   ** 4. Close connection.
   *********************************************************/
%>    


<%
  /*********************************************************
   ** Function to return all results.
   *********************************************************/
  function getAllRecs()
  {
    Response.Write("<TABLE BORDER='1' CELLSPACING='1' CELLPADDING='3' CLASS='font_normal'>");
    
    // First, retrieve column names.
    var numCols = getFieldCount();
    
    Response.Write("<TR>");
    for (var i = 0; i < numCols; i++)
    {
      Response.Write("<TD ALIGN='center' CLASS='font_bold'>" + objRS.Fields(i).Name + "</TD>");
      
      if (!isEOF())
      {
        doMoveNext();
      }
    }
    Response.Write("</TR>");
    
    // Second, retrieve the rows of data.
    doMoveFirst();
    while (!isEOF())
    {
      Response.Write("<TR>");
      
      for (var j = 0; j < numCols; j++)
      {
        Response.Write("<TD ALIGN='center'>" + objRS(j) + "</TD>");
      }
      
      Response.Write("</TR>");
      doMoveNext();
    }
        
    Response.Write("</TABLE>");
  }
  
  
  /*********************************************************
   ** Function to fill a drop-down box with database fields.
   *********************************************************/
  function doFillDropDown(title)
  {
    Response.Write(
         "<OPTION>Select " + title + "</OPTION>\n"
      + "<OPTION>-------------------------</OPTION>\n");
      
      while (!isEOF())
      {
        Response.Write("<OPTION VALUE='" + objRS(0) + "'>" + objRS(1) + "</OPTION>\n");
        doMoveNext();
      }      
  }
     
  
  /*********************************************************
   ** Function to page through recordsets moving one by one.
   *********************************************************/
  function doRSPagingByOne(pageSize,direction,pageNum,previous,next)
  {
    setPageSize(pageSize);

    if (!((pageNum > 0) || (pageNum < 999)))
    {
	  pageNum = 1;
	}
			
	if (direction == previous)
	{
	  if (pageNum > 1)
	  {
	    pageNum--;
	  }
	  else
	  {
	    pageNum = 1;
	  }
	}
	else if (direction == next)
	{
	  if (getAbsolutePage() < getPageCount())
	  {
	    pageNum++;
	  }
	  else
	  {
	    pageNum = getPageCount();
	  }
	}
	else
	{
	  pageNum = 1;
	}

	setAbsolutePage(pageNum);
	
	return pageNum;
  }

  
  /*********************************************************
   ** Function to move through a recordset in sets, depending on which set is chosen.
   *********************************************************/
  function doRSPagingByChosen(pageSize,pageName,extraParams)
  {
    // Request page number and handle page number errors.			 
	var numPage = Request("PageNo");
			 
	if (!((numPage > 0) || (numPage < 999)))
	{
	  numPage = 0;
	}
				     
	// Open a recordset and establish the page size.
	setPageSize(pageSize);			 
			 
	// Handle paging increments and paging decrements.			 
	if (getAbsolutePage() < getPageCount())
	{
	  numPage++;
	}
	else
	{
	  numPage = getPageCount();
	}
						
	// Establish the absolute page.
	setAbsolutePage(numPage);					 			 
					 			 
	// Show paging navigation.	
    doDisplayPaging(numPage,pageName,extraParams);
  }
  
  
  /*********************************************************
   ** Function to display paging navigation.
   *********************************************************/
  function doDisplayPaging(numPage,pageName,extraParams)
  {
	var numPageIterator = (numPage - 1);
	
	if (numPageIterator < 10)
	{
	  var numPageNext10 = 10;
	}
	else
	{
	  var strPageIterator = new String(numPageIterator);
	  var strPageDigit = strPageIterator.charAt(0);
	  var numPageDigit = new Number(strPageDigit);
	  numPageDigit = numPageDigit + 1;
	  var strNewNext10 = numPageDigit;
	  strNewNext10 = strNewNext10 + "0";
	  var numPageNext10 = new Number(strNewNext10);
	}
	
	var numPageEnd = (getPageCount() - numPageNext10);
		
	// if the number of pages <= 10 then display "1 - 10".
	if (getPageCount() <= 10)
	{		 
	  for (var z = 0; z < getPageCount(); z++)
	  {
	    Response.Write("<A HREF=" + pageName + "?PageNo=" + z + extraParams + ">" 
	      + (z + 1) + "</A>&nbsp;&nbsp;");
	  }
	} // end of <= 10 paging.
	
	// if the number of pages > 10 then
	//  show paging in sets of 10.
	//    e.g. 1 - 10, 11-20, etc.
	else
	{
	  if (numPageIterator >= 10) 
	  {
	    Response.Write("<A HREF=" + pageName + "?PageNo=" + (numPageNext10 - 20) + extraParams + ">"
	      + "<<-Previous 10</A>&nbsp;&nbsp;");	      
	  
	    numPageIterator++;
	    
	    for (numPageIterator = (numPageNext10 - 9); numPageIterator <= numPageNext10; numPageIterator++)
	    {
	      Response.Write("<A HREF=" + pageName + "?PageNo=" + (numPageIterator - 1) + extraParams + ">" 
	        + numPageIterator + "</A>&nbsp;&nbsp;");
	    }
	    	    
	  } // End of page iterator >= 10.
	  else
	  {
	    for (numPageIterator = 1; numPageIterator <= 10; numPageIterator++)
	    {
	      Response.Write("<A HREF=" + pageName + "?PageNo=" + (numPageIterator - 1) + extraParams + ">"
	        + numPageIterator + "</A>&nbsp;&nbsp;");
	    }
	  } // End of page iterator < 10. 
	  
	  if (numPageEnd >= 1)
	  {
	    Response.Write("<A HREF=" + pageName + "?PageNo=" + numPageNext10 + extraParams + ">"
	      + "Next 10->></A>&nbsp;&nbsp;");
	  } // end of next 10 paging.
	} // end of > 10 paging.    
	
	// Destory objects.
	if (numPageIterator >= 10)
	{
	  strPageIterator = null;
	  numPageDigit = null;
	  numPageNext10 = null;
	}
  } 
  
  
  /*********************************************************
   ** Function to display a recordset's header.
   *********************************************************/
  function doDisplayRSHeader()
  {
    for (var a = 0; a < getFieldCount(); a++)
	{
	  Response.Write("<TH>" + getFieldName(a) + "</TH>");	  
	}
  }
  
  
  /*********************************************************
   ** Function to display a recordset.
   *********************************************************/
  function doDisplayRS(tableBorder,displayHeader)
  {
    // Only display header if headings should appear above each column.
    if (displayHeader == true)
    {			 
	  Response.Write("<TABLE BORDER='" + tableBorder + "'>");	  
	  doDisplayRSHeader();
	}  
		
	for (var j = 0; j < getPageSize(); j++)
	{
	  if (isEOF())
	  {
	    break;
	  }	  
	
	  if (displayHeader == true)
	  {
	    Response.Write("<TR>");  	    	    
	  }
	  else
	  {
	    Response.Write("<TABLE BORDER='" + tableBorder + "'>");
	  }
	  	  	  		   
	  for (var i = 0; i < getFieldCount(); i++)
	  {
	    if (displayHeader == true)
	    {
	      Response.Write("<TD>" + getFieldValue(i) + "</TD>");	      
	    }
	    else
	    {
	      Response.Write("<TR>"
	        + "<TD><B>" + getFieldName(i) + "</B></TD>"
	        + "<TD>" + getFieldValue(i) + "</TD>"
	        + "</TR>");
	    }	      
	  }
	  
	  if (displayHeader == true)
	  {		   
	    Response.Write("</TR>");	  	        	   
	  }
	  else
	  {
	    Response.Write("</TABLE> <P>");	
	  }
	  
	  doMoveNext();
	}
	
	if (displayHeader == true)
	{
	  Response.Write("</TABLE> <P>");
	}	  
  } 
%>