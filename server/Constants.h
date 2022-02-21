#ifndef CONSTANTS_H
#define CONSTANTS_H 

#define CLIENT_DICE_ROLL "000" // %2d, rolled number
#define CLIENT_BUY_DEV_CARD "001" // %d, dev card
#define CLIENT_TRADE "002" //%2d%s, string len, string trade (4sheep&2wheat=3ore)
#define CLIENT_BUY_ROAD "003" //%2d%2d, hex index, side index
#define CLIENT_UPGRADE_CITY "004" // %2d%d, hex index, corner index
#define CLIENT_MOVE_ROBBER "005" // %2d, hex index
#define CLIENT_END_TURN "006" 
#define CLIENT_OPEN_KNIGHT "007" //%2d%d, hex index, color to take from
#define CLIENT_OPEN_VICTORY_POINT "008" 
#define CLIENT_BUY_SETTLEMENT "009" //%2d%d, hex index, corner index
#define CLIENT_OPEN_YEAR_OF_PLENTY "010" //%d%d, resource1, resource2 
#define CLIENT_OPEN_MONOPOLY "011" //%d, resource
#define CLIENT_GET_CURRENT_POINTS "012" 
#define CLIENT_ACCEPT_TRADE "013" 
#define CLIENT_DECLINE_TRADE "014" 
//when 7 is rolled
#define CLIENT_DISCARD_CARDS "024" //%d%s, len, resources (111) means 3 ore

#define SERVER_START_TURN "015" 
#define SERVER_OFFER_TRADE "017"
#define SERVER_FINAL_TRADE_POSITIVE "018"
#define SERVER_FINAL_TRADE_NEGATIVE "019"
#define SERVER_ACCEPT_OPERATION "020"
#define SERVER_DECLINE_OPERATION "021" 
#define SERVER_GIVE_CURRENT_POINTS "022" //%d, points
#define SERVER_GIVE_STOLEN_CARD "023"
#define SERVER_GIVE_RESOURCES "025"
#define SERVER_VICTORY "016" // %d, color

#endif 