#!/bin/bash
PS3='Please enter your choice: '
options=("vector" "stack" "map" "set" "quit")
select opt in "${options[@]}"
do
    case $opt in
        "vector")
            echo "you chose vector test"
			cat make_vector > Makefile
			make re
			DEFAULT='\033[0m'
			RED='\033[1;31m'
			GREEN='\033[1;32m'
			YELLOW='\033[0;33m'
			CYAN='\033[0;36m'
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Vector Tests Begin${CYAN} **************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
			declare -i var1=0
			declare -i var2=1
			echo -e "${YELLOW}Redirecting ft_container to ft${DEFAULT}"
			for f in ./exe_ft/ft_*; do \
				./$f > ./exe_ft/$var1; \
				var1=`expr $var1+$var2`
			done
			declare -i var1=0
			echo -e "${YELLOW}Redirecting std_container to std${DEFAULT}"
			for f in ./exe_std/std_*; do \
				./$f > ./exe_std/$var1; \
				var1=`expr $var1+$var2`
			done
			echo "var1 = " $var1
			echo -e "${YELLOW}diff ft std${DEFAULT}"
			var2=`expr 0`
			mkdir exe
			for ((i=0; i<$var1; i++))
			do
				diff ./exe_ft/$i ./exe_std/$i > ./exe/final$i ;\
			done
			declare -i var3=1
			declare -i var4=0
			for ((i=0; i<$var1; i++))
			do
			if [ -s ./exe/final$i ]; then
					echo -e "${RED}FAILED -42${DEFAULT}"
				else
					var4=`expr $var4+$var3`
					echo -e "${GREEN}PASS 125${DEFAULT}"
				fi
			done
			echo -e "${CYAN}---------------------------------------------${DEFAULT}"
			echo -e "${YELLOW}$var4 / $i OK ${DEFAULT}"
			rm -rf exe
			make fclean
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Vector Tests Ends${CYAN} ***************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
            ;;
        "stack")
            echo "you chose stack test"
			cat make_stack > Makefile
			make re
			DEFAULT='\033[0m'
			RED='\033[1;31m'
			GREEN='\033[1;32m'
			YELLOW='\033[0;33m'
			CYAN='\033[0;36m'
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Stack Tests Begin${CYAN} **************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
			declare -i var1=0
			declare -i var2=1
			echo -e "${YELLOW}Redirecting ft_container to ft${DEFAULT}"
			for f in ./exe_ft/ft_*; do \
				./$f > ./exe_ft/$var1; \
				var1=`expr $var1+$var2`
			done
			declare -i var1=0
			echo -e "${YELLOW}Redirecting std_container to std${DEFAULT}"
			for f in ./exe_std/std_*; do \
				./$f > ./exe_std/$var1; \
				var1=`expr $var1+$var2`
			done
			echo "var1 = " $var1
			echo -e "${YELLOW}diff ft std${DEFAULT}"
			var2=`expr 0`
			mkdir exe
			for ((i=0; i<$var1; i++))
			do
				diff ./exe_ft/$i ./exe_std/$i > ./exe/final$i ;\
			done
			declare -i var3=1
			declare -i var4=0
			for ((i=0; i<$var1; i++))
			do
			if [ -s ./exe/final$i ]; then
					echo -e "${RED}FAILED -42${DEFAULT}"
				else
					var4=`expr $var4+$var3`
					echo -e "${GREEN}PASS 125${DEFAULT}"
				fi
			done
			echo -e "${CYAN}---------------------------------------------${DEFAULT}"
			echo -e "${YELLOW}$var4 / $i OK ${DEFAULT}"
			rm -rf exe
			make fclean
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Stack Tests Ends${CYAN} ***************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
            ;;
        "map")
            echo "you chose map test"
			cat make_map > Makefile
			make re
			DEFAULT='\033[0m'
			RED='\033[1;31m'
			GREEN='\033[1;32m'
			YELLOW='\033[0;33m'
			CYAN='\033[0;36m'
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Map Tests Begin${CYAN} **************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
			declare -i var1=0
			declare -i var2=1
			echo -e "${YELLOW}Redirecting ft_container to ft${DEFAULT}"
			for f in ./exe_ft/ft_*; do \
				./$f > ./exe_ft/$var1; \
				var1=`expr $var1+$var2`
			done
			declare -i var1=0
			echo -e "${YELLOW}Redirecting std_container to std${DEFAULT}"
			for f in ./exe_std/std_*; do \
				./$f > ./exe_std/$var1; \
				var1=`expr $var1+$var2`
			done
			echo "var1 = " $var1
			echo -e "${YELLOW}diff ft std${DEFAULT}"
			var2=`expr 0`
			mkdir exe
			for ((i=0; i<$var1; i++))
			do
				diff ./exe_ft/$i ./exe_std/$i > ./exe/final$i ;\
			done
			declare -i var3=1
			declare -i var4=0
			for ((i=0; i<$var1; i++))
			do
			if [ -s ./exe/final$i ]; then
					echo -e "${RED}FAILED -42${DEFAULT}"
				else
					var4=`expr $var4+$var3`
					echo -e "${GREEN}PASS 125${DEFAULT}"
				fi
			done
			echo -e "${CYAN}---------------------------------------------${DEFAULT}"
			echo -e "${YELLOW}$var4 / $i OK ${DEFAULT}"
			rm -rf exe
			make fclean
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Map Tests Ends${CYAN} ***************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
            ;;
        "set")
            echo "you chose set test"
			cat make_set > Makefile
			make re
			DEFAULT='\033[0m'
			RED='\033[1;31m'
			GREEN='\033[1;32m'
			YELLOW='\033[0;33m'
			CYAN='\033[0;36m'
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Set Tests Begin${CYAN} **************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
			declare -i var1=0
			declare -i var2=1
			echo -e "${YELLOW}Redirecting ft_container to ft${DEFAULT}"
			for f in ./exe_ft/ft_*; do \
				./$f > ./exe_ft/$var1; \
				var1=`expr $var1+$var2`
			done
			declare -i var1=0
			echo -e "${YELLOW}Redirecting std_container to std${DEFAULT}"
			for f in ./exe_std/std_*; do \
				./$f > ./exe_std/$var1; \
				var1=`expr $var1+$var2`
			done
			echo "var1 = " $var1
			echo -e "${YELLOW}diff ft std${DEFAULT}"
			var2=`expr 0`
			mkdir exe
			for ((i=0; i<$var1; i++))
			do
				diff ./exe_ft/$i ./exe_std/$i > ./exe/final$i ;\
			done
			declare -i var3=1
			declare -i var4=0
			for ((i=0; i<$var1; i++))
			do
			if [ -s ./exe/final$i ]; then
					echo -e "${RED}FAILED -42${DEFAULT}"
				else
					var4=`expr $var4+$var3`
					echo -e "${GREEN}PASS 125${DEFAULT}"
				fi
			done
			echo -e "${CYAN}---------------------------------------------${DEFAULT}"
			echo -e "${YELLOW}$var4 / $i OK ${DEFAULT}"
			rm -rf exe
			make fclean
			echo -e "${CYAN}*********************************************${DEFAULT}"
			echo -e "${CYAN}*********** ${YELLOW}Set Tests Ends${CYAN} ***************${DEFAULT}"
			echo -e "${CYAN}*********************************************${DEFAULT}"
            ;;
        "quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done

