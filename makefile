FLAGS = -g -Wall -Wextra -Ilibs
OUTPUT = build
LIBS = $(wildcard libs/*)

all: $(OUTPUT)

$(OUTPUT): main.cpp $(LIBS)
	@g++ $(FLAGS) main.cpp -o $(OUTPUT)

run: $(OUTPUT)
	@./$(OUTPUT) < input.txt 

debug: $(OUTPUT)
	@gdb --tui -x gdb.txt ./$(OUTPUT)

check_automatically:
	@while true; do errors=$$(make check | grep -E ".[ch]pp:[0-9]+:[0-9]+" | sed "s/__cxx11::basic_string<char>/string/g" | sed -E "s/(std::)?allocator[^>]*>//g");  numberOfWords=$$(echo $$errors | wc -w); clear; [ $$numberOfWords -gt 0 ]  && echo -e "\033[31mERROR\033[0m" || (echo -e "\033[32mALL OK\033[0m" && make run); echo "$$errors" | awk '{printf "\033[33m%s\033[0m \033[36m%s\033[0m\n", $$1, substr($$0, length($$1)+2)}' ; sleep 10; done

tests:
	@for file in ./tests/[^g]*; do echo -n $$(echo $$file | cut -f 3 -d "/"):; g++ $(FLAGS) $$file -o $(OUTPUT) && ./$(OUTPUT) && echo -e "\033[32mTest Passed\033[0m" || echo -e "\033[31mTest Failed\033[0m" && break; done

clean:
	rm -rf $(OUTPUT)

check:
	@g++ $(FLAGS) -fsyntax-only main.cpp libs/*.hpp 2>&1 | grep -v "pragma once"

analize:
	@valgrind --tool=callgrind ./$(OUTPUT) < input.txt
	@kcachegrind callgrind.*
	@rm callgrind.*

.PHONY: all run debug clean check check_automatically analize tests
