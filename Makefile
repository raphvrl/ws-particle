CXX = gcc

SRC_DIR = ./src
INCLUDE_DIR = ./include
OBJ_DIR = ./bin

TARGET = test

SRC += $(wildcard $(SRC_DIR)/*.c)
SRC += $(wildcard $(SRC_DIR)/*/*.c)

OBJ += $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

HEADER = $(wildcard $(INCLUDE_DIR)/*.h) $(wildcard $(INCLUDE_DIR)/*/*.h)

CXXFLAGS = -I$(INCLUDE_DIR) 
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

DEL = rm -f
PRINT = echo -e

SRC_FILE_NBR = $(words $(SRC))
SRC_NBR = 1

YELLOW = \033[1;33m
GREEN = \033[1;32m
NC = \033[0m

$(TARGET): $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)
	@$(PRINT) "$(YELLOW)[$(GREEN)100%$(YELLOW)]$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADER)
	@$(PRINT) "$(YELLOW)[$(GREEN)$$((($(SRC_NBR) * 100) / $(SRC_FILE_NBR)))%$(YELLOW)]$(NC)"
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS)
	@$(eval SRC_NBR=$(shell echo $$(($(SRC_NBR) + 1))))

all: $(TARGET) run

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(TARGET)

re: fclean all

run: $(TARGET)
	@./$(TARGET)

.PHONY: all clean fclean re run
