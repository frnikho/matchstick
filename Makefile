NAME		=	matchstick
TNAME		=	unit_tests

SRCPATH		=	src
TESTPATH	=	tests
MAINPATH	=	src

SRC 		=	$(SRCPATH)/matchstick/board.c			\
				$(SRCPATH)/matchstick/match.c			\
				$(SRCPATH)/matchstick/matchstick.c		\
				$(SRCPATH)/input/read_input.c			\
				$(SRCPATH)/input/game_input.c			\
				$(SRCPATH)/ia/ia.c


MAIN		=	$(MAINPATH)/main.c

TESTS		=	$(TESTPATH)/test_matchstick.c			\
				$(TESTPATH)/test_match.c

LIB			=	-L lib -lmy

OBJ			=	$(SRC:%.c=%.o)
OBJMAIN		=	$(MAIN:%.c=%.o)
OBJTESTS	=	$(TESTS:%.c=%.o)

INCLUDE		=	-I include/
CFLAGS		=	$(INCLUDE) $(LIB)
TFLAGS		=	-lcriterion

all:			$(NAME)
$(NAME):		$(OBJ) $(OBJMAIN)
				make -C lib/
				$(CC) -o $(NAME) $(OBJMAIN) $(OBJ) $(CFLAGS)
clean:
				rm -rf $(OBJ) $(OBJTESTS)
fclean:			clean
				make -C lib/ clean
				make -C lib/ fclean
				rm -rf $(NAME) $(TNAME)
re:				fclean all
test_run:		re $(OBJTESTS)
				gcc -o $(TNAME) $(OBJ) $(OBJTESTS) $(TFLAGS) $(CFLAGS)