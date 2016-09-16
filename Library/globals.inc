<%
  // General Purpose global variables.  Must be included at top of every webpage.

  // Beginning of the site's URL.
  var g_Server = "http://" + Request.ServerVariables("SERVER_NAME");
  
  // Global page title.  Must be modified per site.  
  var g_PageTitle = "";
  
  // Web browser detection.  Specifically detects IE.  
  var g_UserAgent = Request.Servervariables("HTTP_USER_AGENT");
  var g_Browser = new RegExp("MSIE");
  var g_IE = g_Browser.test(g_UserAgent);  
%>
