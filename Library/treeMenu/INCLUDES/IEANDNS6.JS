//************************ Netscape 6 and IE functions *****************************

function show(id,id2,id3) {
	if(document.getElementById) {
		var obj = document.getElementById(id);
		var obj3 = document.getElementById(id3);
			obj.className = 'off';
			obj.isShowing = false;
			obj2.src = 'images/ftv2pnode.gif';
		}
			obj.className = 'on';
			obj.isShowing = true;
			obj3.src = 'images/ftv2folderopen.gif';
	}
}

function showLast(id,id2,id3) {
	if(document.getElementById) {
		var obj = document.getElementById(id);
		var obj3 = document.getElementById(id3);
			obj.className = 'off';
			obj.isShowing = false;
			obj2.src = 'images/ftv2plastnode.gif';
		}
			obj.className = 'on';
			obj.isShowing = true;
			obj3.src = 'images/ftv2folderopen.gif';
	}
}