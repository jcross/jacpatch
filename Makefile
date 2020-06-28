PATCHDIR := patches
DOSDIR := bind
LINDIR := binl
PATCHES := $(wildcard $(PATCHDIR)/*.jac)
BINDS := $(addprefix $(DOSDIR)/, $(notdir $(PATCHES:.jac=.exe)))
BINLS := $(addprefix $(LINDIR)/, $(notdir $(PATCHES:.jac=)))

all: linux dos

clean:
	rm -rf $(LINDIR)
	rm -rf $(DOSDIR)
	rm -f hardInput


linux: $(BINLS)
dos: $(BINDS)

$(LINDIR):
	mkdir $(LINDIR)

$(DOSDIR):
	mkdir $(DOSDIR)

$(LINDIR)/%: $(PATCHDIR)/%.jac | $(LINDIR)
	ln -s $< hardInput
	xxd -i hardInput > src/hardInput.h
	gcc src/main.c  -W -Wall -s -Os -o $@
	rm hardInput


$(DOSDIR)/%.exe: $(PATCHDIR)/%.jac | $(DOSDIR)
	ln -s $< hardInput
	xxd -i hardInput > src/hardInput.h
	ia16-elf-gcc -W -Wall -s -Os -mcmodel=small src/main.c -o $@ -li86
	rm hardInput
