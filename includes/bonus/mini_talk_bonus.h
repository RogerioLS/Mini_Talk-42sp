/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:58:17 by roglopes          #+#    #+#             */
/*   Updated: 2024/01/25 15:28:17 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief MINI TALK
 * 
 * The purpose of the program is to demonstrate a basic form of 
 * nter-process communication using custom signals (SIGUSR1 and SIGUSR2) 
 * to transmit binary data. The client encodes a string into binary and 
 * sends it bit by bit to the server, which decodes the bits and 
 * reconstructs the original string.
*/
#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H

/**
 * @brief Includes librarys for program.
 * 
 * @include signal -> Including signal.h in a C program allows you to 
 * work with signals, which are a form of interprocess communication 
 * used in Unix and Unix-like operating systems;
 * 
 * @include libft  -> Lib built in projects 42;
*/
# include <signal.h>
# include "../../libft/include/libft.h"

/**
 * @brief The goal is to deal with specific signals such as 
 * SIGUSR1 and SIGUSR2.
 * 
 * @param singal An integer representing the signal number 
 * that triggered the handler.
 * @param info A pointer to a siginfo_t structure containing 
 * additional information about the signal.
 * @param context A pointer to a ucontext_t structure providing 
 * the context in which the signal was delivered. 
 * In this function, it is not used ((void)context), likely 
 * to avoid compiler warnings about an unused parameter.
*/
void	ft_receive_signal(int signal, siginfo_t *info, void *context);

/**
 * @brief Function designed to send bits of a character to
 * another process using signals, specifically the SIGUSR1
 * and SIGUSR2 signals.
 * 
 * @param pid The ID of the target process to which signals
 * will be sent.
 * @param c A character (unsigned char) whose bits will be
 * sent as signals.
*/
void	ft_send_signal(int pid, unsigned char c);

/**
 * @brief Function designed to check whether the parameters
 * passsed to the program are valid.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Vector of strings that contain the arguments
 * passed to the program.
*/
void	ft_check_parameters(int argc, char *argv[]);

/**
 * @brief This function acts as a client in a signal commu-
 * nication system.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Vector of strings that contain the arguments
 * passed to the program.
*/
void	ft_main_client(int argc, char *argv[]);

/**
 * @brief This function works as server in a signal commu-
 * nication system.
*/
void	ft_main_server(void);

#endif