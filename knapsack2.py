#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
#
# xxx.py
# Description: Project Euler - Problem #xxx
# -----------------------------------------------------------------------------
#
# Started on  <Mon Mar  1 16:05:47 2010 Carlos Linares>
# Time-stamp: <Monday, 02 December 2013 00:22:34 Carlos Linares Lopez (clinares)>
# -----------------------------------------------------------------------------
#
# $URL::                                                                     $
# $Id::                                                                      $
# $Date::                                                                    $
# $Revision::                                                                $
# -----------------------------------------------------------------------------
#
# Made by Carlos Linares
# Login   <clinares@jupiter>
#

"""
 Solve the 2d-version of the knapsack problem using dynamic programming
 values and weights are read from a single file which contains an item per line
 with the following information (weight, value). The file is preceded of a first
 line with the number of items and the total capacity
 To solve the case shown in stackexchange (Finding the n-best items in a 0/1
 Knapsack), use a file (call it "test3") with the following contents:
 3 5
 1 1
 4 1
 3 1
 and execute this program as follows:
 $ ./knapsack2.py --file test3 --maxitems 2
 The output shows that the solution consists of items 2 and 3
"""

# imports
# -----------------------------------------------------------------------------
import argparse         # parser for command-line options
import getopt           # variable-length params
import sys              # argv
import time             # time handling

from collections import defaultdict

# -----------------------------------------------------------------------------

# globals
# -----------------------------------------------------------------------------
PROGRAM_VERSION = "0.1.0"

# -----------------------------------------------------------------------------

# funcs
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# create_parser
#
# creates a command-line parser
# -----------------------------------------------------------------------------
def create_parser ():
		"""
		creates a command-line parser
		"""

		# create the parser
		parser = argparse.ArgumentParser (description="""
 Solve the 2d-version of the knapsack problem using dynamic programming
 values and weights are read from a single file which contains an item per line
 with the following information (weight, value). The file is preceded of a first
 line with the number of items and the total capacity
 -----------------------------------------------------------------------------
""",
																			formatter_class=argparse.RawDescriptionHelpFormatter)

		# Group of optional arguments
		required = parser.add_argument_group ("Optional arguments", "The following arguments are optional")
		required.add_argument ('-n', '--maxitems',
													 type=int,
													 default=-1,
													 help ="specifies the maximum number of items to put into the knapsack. By default, all")

		# Group of required arguments
		required = parser.add_argument_group ("Required arguments", "The following arguments are required")
		required.add_argument ('-f', '--file',
													 help ="specifies the file with the specification of the problem")

		# Group of miscellaneous arguments
		misc = parser.add_argument_group ('Miscellaneous')
		misc.add_argument ('-v', '--verbose',
											 action='store_true',
											 help="shows additional information")
		misc.add_argument ('-V', '--version',
											 action='version',
											 version=" %s %s" % (sys.argv [0], PROGRAM_VERSION),
											 help="output version information and exit")

		# and return the parser
		return parser


# -----------------------------------------------------------------------------
# solve2d
#
# solve the 2d-knapsack problem specified in its parameters: capacity is the
# overall capacity of the knapsack and the ith position of the arrays value and
# weight specify the value and weight of the ith item
# -----------------------------------------------------------------------------[
def solve2d (capacity, value, weight):
		"""
		solve the 2d-knapsack problem specified in its parameters: capacity is the
		overall capacity of the knapsack and the ith position of the arrays value
		and weight specifies the value and weight of the ith item
		"""

		# initialization - the number of items is taken from the length of any array
		# which shall have the same length
		nbitems = len (value)

		# we use dynamic programming to solve this problem. Thus, we'll need a table
		# that contains (N, M) cells where 0<=N<=capacity and 0<=M<=nbitems
		table=dict ()
		
		# initialize the contents of the dictionary for all capacities to another
		# dictionary which returns 0 by default
		for icapacity in range (0, 1+capacity):
				table [icapacity] = defaultdict (int)

		# now we are ready to start, ... for the first j items
		for j in range (0, nbitems):

				# for all capacities ranging from 1 to the maximum overall capacity
				for i in range (1, 1+capacity):

						# if this item can not be inserted
						if (weight [j] > i):
								table [i][1+j] = table [i][j]   # just do not add it

						# otherwise, consider inserting it
						else:
								table [i][1+j] = max (table[i][j],  # do not add this item
																			table[i-weight[j]][j]+value[j])

		# return the table computed so far
		return table


# -----------------------------------------------------------------------------
# solve3d
#
# solve the 3d-knapsack problem specified in its parameters: capacity is the
# overall capacity of the knapsack and the ith position of the arrays value and
# weight specify the value and weight of the ith item. This is called the
# 3d-knapsack not because it refers to a cuboid but because it also considers a
# maximum number of items to insert which is given in the last parameter
# -----------------------------------------------------------------------------
def solve3d (capacity, value, weight, maxitems):
		"""
		solve the 3d-knapsack problem specified in its parameters: capacity is the
		overall capacity of the knapsack and the ith position of the arrays value
		and weight specify the value and weight of the ith item. This is called the
		3d-knapsack not because it refers to a cuboid but because it also considers
		a maximum number of items to insert which is given in the last parameter
		"""

		print
		print "Solving 3d ..."
		print

		# initialization - the number of items is taken from the length of any array
		# which shall have the same length
		nbitems = len (value)

		# we use dynamic programming to solve this problem. Thus, we'll need a table
		# that contains (N, M) cells where 0<=N<=capacity and 0<=M<=nbitems
		table=dict ()
		
		# initialize the contents of the dictionary for all capacities and number of
		# items to another dictionary which returns 0 by default
		for icapacity in range (0, 1+capacity):
				table [icapacity]=dict ()
				for items in range (0, 1+nbitems):
						table [icapacity][items] = defaultdict (int)

		# now we are ready to start, ... for the first j items
		for j in range (0, nbitems):

				# for all capacities ranging from 1 to the maximum overall capacity
				for i in range (1, 1+capacity):

						# and for all cardinalities of items from 1 until the maximum
						# allowed
						for k in range (1, 1+maxitems):

								# if this item can not be inserted
								if (weight [j] > i):
										table [i][1+j][k] = table [i][j][k]   # just do not add it
										
								# otherwise, consider inserting it
								else:
										
										# if this is item is known to fit the knapsack (because its
										# weight does not exceed the current capacity and adding it
										# creates a set with a cardinality less or equal than the
										# cardinality currently considered), then compute the
										# optimal value as usual but considering sets of the same
										# cardinality (k)
										if (j<k):
												table [i][1+j][k] = max (table[i][j][k],
																								 table[i-weight[j]][j][k]+value[j])

										else:
												prev = []

												# retrieve the optimal solution for all values of
												# (i-weight[j], kappa [0 .. j-1], k-1)
												for kappa in range (0, 1+j):
														prev.append (table[i-weight[j]][kappa][k-1])

												# and consider inserting this item taking into account
												# the optimal solution from the preceding cardinality
												# considering all sets of items
												table [i][1+j][k] = max (table[i][j][k],
																								 max (prev) + value[j])
										
		# return the table computed so far
		return table


# -----------------------------------------------------------------------------
# parse
#
# parses the given file and returns a tuple with the overall capacity specified
# in the file and also the vectors value and weight that actually specify those
# parameters for all items
# -----------------------------------------------------------------------------
def parse (filename):
		""" 
		parses the given file and returns a tuple with the overall capacity
		specified in the file and also the vectors value and weight that actually
		specify those parameters for all items
		"""

		# initialization
		value = list ()
		weight = list ()

		with open (filename, 'r') as stream:

				lines=stream.readlines ()

				# copy the number of items and overall capacity of the knapsack which
				# are specified in the first line of the inputfile
				line = lines[0].split (' ')
				(nbitems, capacity) = (int (line [0].strip ()), int (line[1].strip ()))

				# now, process the rest of the lines and add their values to the value
				# and weight arrays
				for iline in range (1, 1+nbitems):
						line = filter (lambda x:x, lines[iline].split (' '))
						value.append  (int (line [0].strip ()))
						weight.append (int (line [1].strip ()))

		# and return the capacity, and value and weight vectors
		return (capacity, value, weight)


# -----------------------------------------------------------------------------
# show2d
#
# shows the whole table generated by the solve2d procedure
# -----------------------------------------------------------------------------
def show2d (capacity, value, weight, table):
		""" 
		shows the whole table generated by the solve2d procedure
		"""

		# initialization - the number of items is taken from the length of any array
		# which shall have the same length
		nbitems = len (value)

		# show the header
		print
		print " Overall capacity: %i" % capacity
		print " # of items: %i" % nbitems
		print " Value of the items: "
		print "\t ",
		print value
		print " Weight of the items: "
		print "\t ",
		print weight
		print

		# and now, for all capacities ranging from zero to the maximum overall
		# capacity
		for i in range (0, 1+capacity):

				# and all sets of items, from 0 to the maximum number of items
				for j in range (0, 1+nbitems):

						print "%4d " % table[i][j],

				print

# -----------------------------------------------------------------------------
# show3d
#
# shows the whole table generated by the solve3d procedure
# -----------------------------------------------------------------------------
def show3d (capacity, value, weight, table, maxitems):
		""" 
		shows the whole table generated by the solve3d procedure
		"""

		# initialization - the number of items is taken from the length of any array
		# which shall have the same length
		nbitems = len (value)

		# show the header
		print
		print " Overall capacity: %i" % capacity
		print " # of items: %i" % nbitems
		print " maximum number of items: %i" % maxitems
		print " Value of the items: "
		print "\t ",
		print value
		print " Weight of the items: "
		print "\t ",
		print weight
		print

		# and now, for all cardinalities of the items
		for k in range (0, 1+maxitems):

				print " Maximum number of items: %i" % k

				# and all capacities ranging from zero to the maximum overall capacity
				for i in range (0, 1+capacity):

						# and all sets of items, from 0 to the maximum number of items
						for j in range (0, 1+nbitems):

								print "%4d " % table[i][j][k],

						print

				print
				print

# main
# -----------------------------------------------------------------------------
if __name__=='__main__':
		
		PROGRAM_NAME = sys.argv[0]          # get the program name

		# process the command-line arguments
		PARSER = create_parser ()
		ARGS = PARSER.parse_args ()

		# start the chronometer
		START = time.clock ()

		# parse the input file
		(CAPACITY, VALUE, WEIGHT) = parse (ARGS.file)

		# solve it and show the solution
		if (ARGS.maxitems == -1):
				TABLE = solve2d (CAPACITY, VALUE, WEIGHT)
				show2d (CAPACITY, VALUE, WEIGHT, TABLE)
				
		else:
				TABLE = solve3d (CAPACITY, VALUE, WEIGHT, ARGS.maxitems)
				show3d (CAPACITY, VALUE, WEIGHT, TABLE, ARGS.maxitems)

		# stop the chronometer
		STOP  = time.clock ()

		# show the elapsed time
		SECONDS = (STOP-START) % 60
		MINUTES = (STOP-START-SECONDS) / 60
		print """
 [Info: %02i:%02i minutes:seconds elapsed]
					""" % (MINUTES, SECONDS)


# Local Variables:
# mode:python
# fill-column:80
# End: