all: shared

shared:
	gcc patliteusb_cli.c -o patliteusb_cli $$(pkg-config --libs libusb-1.0)

#static:
#	gcc -o patliteusb_static patliteusb_cli.c -static -L. -lusb-1.0 -lpthread 

clean:
	rm patliteusb_cli

.PHONY: all
