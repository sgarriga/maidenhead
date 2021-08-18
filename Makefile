all: maidenhead

install: maidenhead
	sudo cp maidenhead /usr/local/bin/maidenhead
	sudo chown root:root /usr/local/bin/maidenhead
	sudo chmod a+x /usr/local/bin/maidenhead
