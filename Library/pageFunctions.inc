<%
// Function to cycle through pages, such as search results.
function doPaging(page,numRecs,buffer,pageId,params)
{
  var numPages = new Number(Math.ceil(numRecs / buffer));

  if (pageId >= 1)
  { 
    var i = new Number(pageId);
    var j = new Number((pageId-0) + 9);
    var k = new Number((pageId-0) - 9);
    var end = new Number((numPages-0) - j);
    var back = new Number(i - 1);
      
    if (numPages <= 10)
    {
      for (var i = 1; i < (numPages + 1); i++)
      {
        Response.Write("<A HREF='" + page + "?Page=" + i + "&Recs=" + numRecs + "&" 
          + params + "'>" + i + "</A>"
          + "&nbsp;&nbsp;");        
      }
    }
    else
    {
      if (pageId >= 10)
      {
        Response.Write("<A HREF='" + page + "?Page=" + k + "&Recs=" + numRecs + "&" 
          + params + "'><<-Previous 10</A>"
          + "&nbsp;&nbsp;");
      }
          
      if (i >= 10)
      { 
        i++;
        j++;
        while (i <= j && i < (numPages + 1))
        {
          Response.Write("<A HREF='" + page + "?Page=" + i + "&Recs=" + numRecs + "&" 
            + params + "'>" + i + "</A>"
            + "&nbsp;&nbsp;");
        
          i++;
        }  
      }
      else
      { 
        for (i = 1; i <= 10; i++)
        {
          Response.Write("<A HREF='" + page + "?Page=" + i + "&Recs=" + numRecs + "&" 
            + params + "'>" + i + "</A>"
            + "&nbsp;&nbsp;");            
        }
      }
    
      if (end >= 1)
      {
        Response.Write("<A HREF='" + page + "?Page=" + j + "&Recs=" + numRecs + "&" 
          + params + "'>Next 10->></A>"
          + "&nbsp;&nbsp;");      
      }
    }   
  } 
}
%>