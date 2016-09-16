//************************ Netscape 6 and IE functions *****************************

function show(id,id2,id3) {
	if(document.getElementById) {
		var obj = document.getElementById(id);		var obj2 = document.getElementById(id2);
		var obj3 = document.getElementById(id3);		if(obj.isShowing) {
			obj.className = 'off';
			obj.isShowing = false;
			obj2.src = 'images/ftv2pnode.gif';			obj3.src = 'images/ftv2folderclosed.gif';
		}		else {
			obj.className = 'on';
			obj.isShowing = true;			obj2.src = 'images/ftv2mnode.gif';
			obj3.src = 'images/ftv2folderopen.gif';		}
	}
}

function showLast(id,id2,id3) {
	if(document.getElementById) {
		var obj = document.getElementById(id);		var obj2 = document.getElementById(id2);
		var obj3 = document.getElementById(id3);		if(obj.isShowing) {
			obj.className = 'off';
			obj.isShowing = false;
			obj2.src = 'images/ftv2plastnode.gif';			obj3.src = 'images/ftv2folderclosed.gif';
		}		else {
			obj.className = 'on';
			obj.isShowing = true;			obj2.src = 'images/ftv2mlastnode.gif';
			obj3.src = 'images/ftv2folderopen.gif';		}
	}
}