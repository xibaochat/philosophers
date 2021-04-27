# POTENTIAL errors:
# ./philo_one 50 10 1 1 100

# Basic loop
# 2 10 1 1
# 100 100 1 1

spl_out() {
	echo "[${BLUE}+${NC}] $1"
}

spl_err() {
	echo "[${RED}-${NC}] $1"
}

check_nb_eating () {
	if [[ $# != 3 ]]
	then
		spl_out "${BLUE}Description${NC}: Test the number of time each philosophers ate"
		spl_out "${BLUE}USAGE${NC}: check_nb_eating ${GREEN}i_first ${YELLOW}i_last ${RED}expected_nb_occurence${NC}"
		echo "       ex: check_nb_eating ${GREEN}1       ${YELLOW}100    ${RED}42${NC}"
		spl_err "${RED}Requirement${NC}: ${BLUE}output.txt${NC} MUST already exist"
	else
		i_first=$1
		i_last=$2
		expected_occ=$3
		err=0

		spl_out "Starting to test"
		for phi_i in {$i_first..$i_last}
		do
			res=`grep " $phi_i is eating" output.txt | wc -l`
			if [[ ! $res -eq $expected_occ ]]
			then
				 spl_err "${RED}ERROR${NC} on philo ${BLUE}$phi_i${NC}\t: $res"
				err=1
			fi
		done
		if [[ $err -eq 0 ]]
		then
			spl_out "Everything is ${GREEN}HAO${NC}!${NC}\n    ${PINK}Good job baobao ${NC}❤️ "
		fi
		return $err
	fi
}

check_last_line() {
	if [[ $# < 6  ]]
	then
		spl_out "${BLUE}Description${NC}: Test infinitely if the last line is the expected one"
		spl_out "${BLUE}USAGE${NC}: check_last_line ${GREEN}binary      ${YELLOW}pattern ${RED}test${NC}"
		echo "       ex: check_last_line ${GREEN}./philo_one${NC} ${YELLOW}died${NC}     ${RED}100 1 10 10${NC}"
		spl_err "${RED}Tips${NC}: Use Ctrl+C to stop the test"
	else
		BIN=$1
		EXPECTED_END_LINE=$2
		nb_philo=$3
		ttd=$4
		tte=$5
		tts=$6
		nb_eat=$7
		while true
		do
			$BIN $nb_philo $ttd $tte $tts $nb_eat | tee output.txt | tail -n 1 | grep $EXPECTED_END_LINE > /dev/null
			if [[ ! $? -eq 0 ]]
			then
				echo "[-] ${RED}ERROR${NC}: "
				LAST_LINE=`tail -n 1 output.txt`
				echo "\tLast line is: '${BLUE}$LAST_LINE${NC}'"
				break
			else
				spl_out "${GREEN}HAO${NC}!${NC} ❤️ "
			fi
		done
	fi
}

spl_out "Here are the available functions and there usage\n\n"

spl_out "${PINK}check_nb_eating${NC}"
check_nb_eating

echo "\n"

spl_out "${PINK}check_last_line${NC}"
check_last_line
