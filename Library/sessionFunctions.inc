<%
  // Function to close a logged-in user's session and redirect them.
  function doLogout(page)
  {
    Session.Abandon();
    Response.Redirect(page);
  }
%>