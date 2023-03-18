// https://www.luogu.com.cn/problem/P2482

#include <iostream>
#include <vector>
#include <string>

int n, m;

int deck_idx = 0;
char deck[2000];

bool game_over = false;
bool use_strike = false;

int fp_cnt = 0;

struct Player
{
    std::string persona;
    std::string hand;
    int  hp = 4;
    bool equipped = false;
};

std::vector<Player> players;

inline void discard(int player_idx, int i)
{
    players[player_idx].hand.erase(i, 1);
}

inline int next_player(int player_idx)
{
    int next_idx = (player_idx + 1) % players.size();
    while(players[next_idx].hp == 0)
    {
        next_idx = (next_idx + 1) % players.size();
    }
    return next_idx;
}

inline void draw_cards(int player_idx, int n_cards)
{
    for (int i = 0; i < n_cards; i++)
    {
        players[player_idx].hand.push_back(deck[deck_idx]);
        if (deck_idx < m - 1) { deck_idx++; }
    }
}

inline bool is_enemy(int attacker_idx, int defender_idx)
{
    Player &attacker = players[attacker_idx];
    Player &defender = players[defender_idx];
    if (attacker.persona[0] == 'M' && (defender.persona == "Z0" || defender.persona == "F1")
    ||  attacker.persona[0] == 'Z' &&  defender.persona == "F1"
    ||  attacker.persona[0] == 'F' && (defender.persona == "M1" || defender.persona == "Z1"))
    {
        return true;
    }
    return false;
}

inline bool is_friend(int observer_idx, int observable_idx)
{
    Player &observer   = players[observer_idx];
    Player &observable = players[observable_idx];
    if (observer.persona[0] == 'M' && (observable.persona == "Z1")
    ||  observer.persona[0] == 'F' &&  observable.persona == "F1"
    ||  observer.persona[0] == 'Z' && (observable.persona == "M1" || observable.persona == "Z1")
    ||  observer_idx == observable_idx) // NOTE: everyone is their own friend
    {
        return true;
    }
    return false;
}

inline void expose_identity(int player_idx)
{
    players[player_idx].persona[1] = '1';
}

inline bool can_play_the_card(int player_idx, char card)
{
    int pos = players[player_idx].hand.find(card);
    if (pos != std::string::npos)
    {
        discard(player_idx, pos);
        return true;
    }
    return false;
}

inline void lose_1hp(int attacker_idx, int defender_idx)
{
    Player &attacker = players[attacker_idx];
    Player &defender = players[defender_idx];

    defender.hp--;

    // attempt to self-rescue
    if (defender.hp == 0)
    {
        if (can_play_the_card(defender_idx, 'P'))
        {
            defender.hp++;
        }
    }

    // game over?
    if (defender.hp == 0)
    {
        if (defender.persona[0] == 'M')
        {
            game_over = true;
            return;
        }
        else if (defender.persona[0] == 'F')
        {
            fp_cnt--;
            if (fp_cnt == 0)
            {
                game_over = true;
                return;
            }
        }
    }

    // reward and punishment
    if (defender.hp == 0)
    {
        if (defender.persona[0] == 'F')
        {
            draw_cards(attacker_idx, 3);
        }
        else if (attacker.persona[0] == 'M' && defender.persona[0] == 'Z')
        {
            attacker.hand = "";
            attacker.equipped = false;
        }
    }
}

inline void do_strike(int attacker_idx, int defender_idx)
{
    use_strike = true;
    expose_identity(attacker_idx);

    if (!can_play_the_card(defender_idx, 'D'))
    {
        lose_1hp(attacker_idx, defender_idx);
    }
}

inline int next_enemy(int attacker_idx)
{
    Player &attacker = players[attacker_idx];

    int next_idx = next_player(attacker_idx);
    while(next_idx != attacker_idx)
    {
        Player &next = players[next_idx];
        if (attacker.persona[0] == 'F' &&  next.persona == "M1"
        ||  attacker.persona[0] == 'Z' &&  next.persona == "F1"
        ||  attacker.persona[0] == 'M' && (next.persona == "F1" || next.persona == "Z0"))
        {
            return next_idx;
        }
        next_idx = next_player(next_idx);
    }
    return -1;
}

inline bool can_negate(int attacker_idx, int defender_idx)
{
    if (players[defender_idx].persona[1] != '1') // hidden identity
    {
        return false;
    }

    bool succeeded = false;

    // NOTE: attacker and defender can be friends
    if (is_friend(attacker_idx, defender_idx))
    {
        if (can_play_the_card(attacker_idx, 'J'))
        {
            expose_identity(attacker_idx);
            succeeded = true;
        }
    }

    int latest_idx  = attacker_idx;
    int negator_idx = next_player(latest_idx);

    while(negator_idx != latest_idx)
    {
        Player &negator = players[negator_idx];

        if (is_friend(negator_idx, defender_idx) && !succeeded)
        {
            if (can_play_the_card(negator_idx, 'J'))
            {
                expose_identity(negator_idx);
                succeeded = true;
                latest_idx = negator_idx;
            }
        }
        else if (is_enemy(negator_idx, defender_idx) && succeeded)
        {
            if (can_play_the_card(negator_idx, 'J'))
            {
                expose_identity(negator_idx);
                succeeded = false;
                latest_idx = negator_idx;
            }
        }
        negator_idx = next_player(negator_idx);
    }

    return succeeded;
}

inline void do_duel(int attacker_idx, int defender_idx)
{
    Player &attacker = players[attacker_idx];
    Player &defender = players[defender_idx];

    expose_identity(attacker_idx);

    if (can_negate(attacker_idx, defender_idx))
    {
        return;
    }

    char loser;

    if (attacker.persona[0] == 'M' && defender.persona[0] == 'Z')
    {
        loser = 'D';
    }
    else while(true)
    {
        if (!can_play_the_card(defender_idx, 'K'))
        {
            loser = 'D';
            break;
        }

       if (!can_play_the_card(attacker_idx, 'K'))
        {
            loser = 'A';
            break;
        }
    }

    if (loser == 'D')
    {
        lose_1hp(attacker_idx, defender_idx);
    }
    else
    {
        lose_1hp(defender_idx, attacker_idx);
    }
}

inline void do_aoe(int attacker_idx, char card)
{
    Player &attacker = players[attacker_idx];

    int defender_idx = attacker_idx;
    while((defender_idx = next_player(defender_idx)) != attacker_idx)
    {
        if (can_negate(attacker_idx, defender_idx))
        {
            continue;
        }
        if (attacker.persona == "ZP" && players[defender_idx].persona[0] == 'M')
        {
            attacker.persona[1] = '0';
        }
        if (!can_play_the_card(defender_idx, card))
        {
            lose_1hp(attacker_idx, defender_idx);
        }
        if (game_over)
        {
            return;
        }
    }
}

inline void do_invasion(int attacker_idx)
{
    do_aoe(attacker_idx, 'K');
}

inline void do_arrows(int attacker_idx)
{
    do_aoe(attacker_idx, 'D');
}

inline bool can_play_a_card(int attacker_idx)
{
    Player &attacker = players[attacker_idx];

    for (int i = 0; i < attacker.hand.length(); i++)
    {
        char card = attacker.hand[i];
        if (card == 'P' && attacker.hp < 4)
        {
            discard(attacker_idx, i);
            attacker.hp++;
        }
        else if (card == 'Z')
        {
            discard(attacker_idx, i);
            attacker.equipped = true;
        }
        else if (card == 'K' && (!use_strike || attacker.equipped) && is_enemy(attacker_idx, next_player(attacker_idx)))
        {
            discard(attacker_idx, i);
            do_strike(attacker_idx, next_player(attacker_idx));
        }
        else if (card == 'F' && next_enemy(attacker_idx) != -1)
        {
            discard(attacker_idx, i);
            do_duel(attacker_idx, next_enemy(attacker_idx));
        }
        else if (card == 'N')
        {
            discard(attacker_idx, i);
            do_invasion(attacker_idx);
        }
        else if (card == 'W')
        {
            discard(attacker_idx, i);
            do_arrows(attacker_idx);
        }
        else
        {
            continue;
        }

        // NOTE: attacker can die in a duel
        if (!game_over && attacker.hp > 0) // play a card
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false; // play no card
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    int cur_player;
    players.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> players[i].persona;

        if (players[i].persona == "MP")
        {
            players[i].persona = "M1";
            cur_player = i;
        }

        if (players[i].persona == "FP")
        {
            fp_cnt++;
        }

        for(int j = 0; j < 4; j++)
        {
            players[i].hand.resize(4);
            std::cin >> players[i].hand[j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> deck[i];
    }

    while(!game_over)
    {
        draw_cards(cur_player, 2);
        while(can_play_a_card(cur_player));
        use_strike = false;
        cur_player = next_player(cur_player);
    }

    if (fp_cnt > 0)
    {
        std::cout << "FP\n";
    }
    else
    {
        std::cout << "MP\n";
    }

    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].hp == 0)
        {
            std::cout << "DEAD";
        }
        else for (int j = 0; j < players[i].hand.length(); j++)
        {
            std::cout << players[i].hand[j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
