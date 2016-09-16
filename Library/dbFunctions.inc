<%
  /*********************************************************
   ** NOTE: arrayFunctions.inc must be included in the ASP before this include file.
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
   ** Establish connection and recordset objects.
   *********************************************************/
  var objConn = Server.CreateObject("ADODB.Connection");
  var objRS = Server.CreateObject("ADODB.Recordset");
      
      
  /*********************************************************
   ** Function to open a connection.
   *********************************************************/
  function doOpenConn(conn)
  {
    objConn.Open(conn);
  }
  
  
  /*********************************************************
   ** Function to open a recordset.
   *********************************************************/
  function doOpenRS(sql)
  {
    objRS.Open(sql, objConn, adOpenStatic);
  }
  
  
  /*********************************************************
   ** Function to execute a stored procedure or SQL statement.
   *********************************************************/
  function doExecuteSP(proc)
  {
    objRS = objConn.Execute(proc);
  }  
  
  
  /*********************************************************
   ** Function to envelope text/varchars in single quotes.
   *********************************************************/
  function doQuote(strSQL) 
  {
	var strReturn;
	var strString = new String(strSQL);

	// If empty, just send back the quotes
	if (strString == "") 
	{
	  strReturn = "''";
	} 
	else 
	{
      if (strString == "undefined") 
      {
	    strReturn = "NULL";
	  } 
	  else 
	  {
	    var objRegExp = new RegExp("'", "gi");
		var strReplaceText = "''";

		strReturn = "'" + strString.replace(objRegExp, strReplaceText) + "'";
	  }
	}
	
	return strReturn;
  }


  /*********************************************************
   ** Function to execute a select statement.
   *********************************************************/
  function doSelect(table,columns,criteria1,criteria2,grouping,ordering,jointables,innerjoin)
  {
    // Special care must be taken with the criteria parameter.
    // Separate the value portions of the criteria and check each value.
    //   If the value is zero or an empty string,
    //     do not include this portion of the criteria in the query.          
          
    var strBeginSelect = "SELECT " + columns + " FROM " + table;
    var strWhere = "";
    var strGroup = "";
    var strOrder = "";
    var strJoin = "";
    var strFinalSelect = "";
        
    // Generate "INNER JOIN" criteria.
    if (innerjoin.length >= 1)
    {
      strJoin = " " + doInnerJoin(jointables,innerjoin);
    }
    else
    {
      strJoin = "";
    }
        
    // "Where" criteria.
    if (criteria1.length >= 1 && criteria2.length >= 1)
    {
      // Determine number of criteria portions.
      var numPortions1 = getDimension(criteria1,g_Delimiter);
      var numPortions2 = getDimension(criteria2,g_Delimiter);
       
      // If number of portions (columns and values) are equal, continue.  
      // Otherwise, stop.
      if (numPortions1 == numPortions2)
      {
        // Fill arrays.
        var arrPortion1 = doFillArray(criteria1,g_Delimiter,numPortions1);
        var arrPortion2 = doFillArray(criteria2,g_Delimiter,numPortions2);
        
        // Generate "where" criteria.
        strWhere = " WHERE ";
              
        for (var n = 0; n < numPortions2; n++)
        {
          if (arrPortion2[n] != '0')
          {
            strWhere += arrPortion1[n] + " " + arrPortion2[n] + " AND ";
            }       
          }
              
          strWhere = strWhere.substring(0,(strWhere.length - 5));
        }
        else  // Not same amount of columns and values.
        {
          strWhere = "";
        }
      }
      else  // No "where" criteria.
      {
        strWhere = "";
      }      
            
      // Grouping criteria.
      if (grouping.length >= 1)
      {
        strGroup = " GROUP BY " + grouping;
      }
      else
      {
        strGroup = "";
      }
            
      // Ordering criteria.
      if (ordering.length >= 1)
      {
        strOrder = " ORDER BY " + ordering;
      }
      else
      {
        strOrder = "";
      }
            
      // Concatenate all portions of Select statement.
      strFinalSelect = strBeginSelect + strJoin + strWhere + strGroup + strOrder;
      
      return strFinalSelect;         
  }
  
  
  /*********************************************************
   ** Function to generate an inner join for a select statement.
   *********************************************************/
  function doInnerJoin(tables,joins)
  {
    var strBeginJoin = "INNER JOIN ";
    var numTables = getDimension(tables,g_Delimiter);
    var numCriteria = getDimension(joins,g_Delimiter);
    var strTables = "";
    var strCriteria = "";
    var strFinalJoin = "";
    
    // If there is multiple joins, cater to it.
    // Otherwise, use only one joins.          
    if (numCriteria > 1 && numTables > 1)
    { 
      strFinalJoin = strBeginJoin + " ";
      
      // Fill arrays.
      var arrTable = doFillArray(tables,g_Delimiter,numTables);
      var arrJoin = doFillArray(joins,g_Delimiter,numCriteria);
      
      // Create first part of join (tables).
      for (var j = 0; j < numTables; j++)
      {
        strTables += strBeginJoin + " (" + arrTable[j] + " ";
      }
      
      // Create second part of join (criteria).
      for (var i = 0; i < numCriteria; i++)
      {
        strCriteria += " ON " + arrJoin[i] + ")";
      }
      
      var numLastOpen = strTables.lastIndexOf("(");
      var strTablesPt1 = strTables.substring(0,numLastOpen);      
      var strTablesPt2 = strTables.substring((numLastOpen + 1),strTables.length);
      var strTablesFinal = strTablesPt1 + " " + strTablesPt2;
      var strCriteriaFinal = strCriteria.substring(0,(strCriteria.length - 1));
            
      strFinalJoin = strTablesFinal + " " + strCriteriaFinal;      
    }
    else if (numCriteria == 1 && numTables == 1)
    {
      strFinalJoin = strBeginJoin + " " + tables + " ON " + joins;    
    }
    else
    {
    }
         
    return strFinalJoin;
  }
  
  
  /*********************************************************
   ** Function to execute an insert statement.
   *********************************************************/
  function doInsert(table,columns,values)
  {
    var strInsert = "";
    var strValues = "";
      
    // Establish dimensions of values parameters.
    var numVals = getDimension(values,g_Delimiter);
     
    // Fill values array.
    var arrVals = doFillArray(values,g_Delimiter,numVals);
      
    // Fill string with array elements.
    for (var x = 0; x < arrVals.length; x++)
    {
      strValues += ("'" + arrVals[x] + "', ");
    }
      
    strValues = strValues.substring(0,strValues.length - 2);  
      
    strInsert = "INSERT INTO " + table + " (" + columns + ") VALUES (" + strValues + ")";
        
    return strInsert;       
  }
  
  
  /*********************************************************
   ** Function to get a field name.
   *********************************************************/
  function getFieldName(fieldName)
  {
    return objRS.Fields(fieldName).Name;
  }
  
  
  /*********************************************************
   ** Function to get a field value.
   *********************************************************/
  function getFieldValue(fieldName)
  {
    return objRS.Fields(fieldName).Value;
  }
  
  
  /*********************************************************
   ** Function to get a record count.
   *********************************************************/
  function getRecordCount()
  {
    var numRecs = 0;
  
    while (!objRS.EOF)
    {
      numRecs++;
      objRS.MoveNext();
    }
    
    return numRecs;
  }
  
  
  /*********************************************************
   ** Function to get a field count.
   *********************************************************/
  function getFieldCount()
  {
    return objRS.Fields.Count;    
  }
  
     
  /*********************************************************
   ** Function to get a page count.
   *********************************************************/
  function getPageCount()
  {
    return objRS.PageCount;
  }
  
  
  /*********************************************************
   ** Function to set page size.
   *********************************************************/
  function setPageSize(pageSize)
  {
    objRS.PageSize = pageSize;
    return objRS.PageSize;
  }
  
  
  /*********************************************************
   ** Function to get page size.
   *********************************************************/
  function getPageSize()
  {
    return objRS.PageSize;
  }
  
  
  /*********************************************************
   ** Function to get absolute page.
   *********************************************************/
  function getAbsolutePage()
  {
    return objRS.AbsolutePage;
  }
  
  
  /*********************************************************
   ** Function to set absolute page.
   *********************************************************/
  function setAbsolutePage(pageNum)
  {
    objRS.AbsolutePage = pageNum;
    return objRS.AbsolutePage;
  }
  
  
  /*********************************************************
   ** Function to move to the first record.
   *********************************************************/
  function doMoveFirst()
  {
    objRS.MoveFirst();
  }
  
  
  /*********************************************************
   ** Function to move to the next record.
   *********************************************************/
  function doMoveNext()
  {
    objRS.MoveNext();
  }


  /*********************************************************
   ** Function to establish beginning of file.
   *********************************************************/
  function isBOF()
  {
    return objRS.BOF;
  }
  
  
  /*********************************************************
   ** Function to establish end of file.
   *********************************************************/
  function isEOF()
  {
    return objRS.EOF;
  }
  
  
  /*********************************************************
   ** Function to close a recordset.
   *********************************************************/
  function doCloseRS()
  {
    objRS.Close();    
  }
  
  
  /*********************************************************
   ** Function to close a connection.
   *********************************************************/
  function doCloseConn()
  {
    
    objConn.Close();
    objRS = null;    
    objConn = null;
  }

%>