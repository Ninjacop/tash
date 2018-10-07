# Build the TASH executable
install: main.c
	@echo Compiling source...
	@gcc -o tash main.c
	@echo
	@echo Making the shell executable...
	@chmod 755 tash
	@echo 
	@echo
	@echo BE SURE TO ADD
	@echo 
	@echo PATH=/path/to/tash_executable
	@echo export PATH
	@echo 
	@echo TO YOUR .bashrc OR HOWEVER EXPORTING THE EXECUTABLE\'S PATH 
	@echo CAN BE DONE
	@echo
	
# Remove the TASH executable
clean: 
	@$(RM) tash
	@echo executable has been removed
	@echo