#define define_$(NAME)(T) \
$(RETURN) $(NAME)_##T($(ARGS)){ \
	$(BODY)
}

define_$(NAME)(bool)
define_$(NAME)(char)
define_$(NAME)(short)
define_$(NAME)(int)
define_$(NAME)(long)
define_$(NAME)(float)
define_$(NAME)(double)
