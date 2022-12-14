/*
 *	Feature documentation
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2007, IRIT UPS.
 *
 *	OTAWA is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	OTAWA is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OTAWA; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


/**
 * @mainpage
 *
 * OTAWA (http://www.otawa.fr) is a C++ framework dedicated to static analysis of program
 * in machine language form and more specifically oriented towards WCET (Worst Case Executime
 * Time) computation. These pages represent the automatic documentation of the API of OTAWA
 * (automatically extracted from sources) and is devoted to the OTAWA developer
 * or to the command line user. If your goal is only to compute WCET from the Eclipse environment,
 * refer instead to the OTAWA Eclipse plugin manual.
 *
 * @section reading Reading this document
 *
 * This document contains the automatic documentation of classes composing OTAWA, that is
 * several tenth of classes. Hence, reading documentation of each class according to your
 * needs is definitively the preferred way to use it. If your goal is to learn programming OTAWA, take first a look
 * refer to the OTAWA Manual available in OTAWA_HOME/share/Otawa/doc/manual/manual.html.
 * If you aim to extend your knowledge of OTAWA classes or to look for an available facility,
 * go on here.
 *
 * This document is automatically generated from the automatic documentation of OTAWA classes
 * by the Doxygen utility. This means that all classes, types, functions are documented
 * and may be easily retrieved. For OTAWA concepts, like code processor, identifier and features,
 * you have to fetch the module documentation which outline is given below.
 *
 * If you look for an existing analysis, the good entry point should be the list of features,
 * @ref features. For other facilities, consult the module list in the left frame.
 * In addition, below is a list of standard plugin of OTAWA. To get documentation of a specific
 * class, we advise to use the alphabetic of classes from the menu Classes > Class Index.
 *
 * @section qlinks Quick Links
 *
 * Below is a list of most used modules that you may want to link to:
 *   * @ref features
 *   * @ref prog
 *   * @ref cfg
 *   * @ref faq
 *   * @ref prop
 *   * @ref proc
 *
 *
 * @section content Contents
 *
 * OTAWA is logically split in several modules representing different layers and usage of the
 * framework. In the following, you will find a guide to explore theses modules. Notice that
 * the OTAWA module splitting is not always reflected by the header files and the libraries,
 * specially the kernel module of OTAWA. Notice that each class is member of a module and
 * this documentation provides, just the class name, a straight link to the module
 * documentation that may give more details or put in its context the concerned class.
 *
 * OTAWA is logically split in several layers included in a module:
 * @li @ref prog -- the main module and the root of any work in OTAWA provides the abstract
 * representation of the program to handle.
 * @li @ref prop -- the property layer is built just above the program representation
 * to link properties or annotations to the program representation.
 * @li @ref proc -- this layer supports the chaining and dependency solving of analyzes.
 * @li @ref hard -- this layer provides the description of the host platform where
 * the loaded program will run.
 * @li @ref dfa -- module devoted to generic classes to perform static analyzes.
 * @li @ref ipet -- module containing classes to implement the WCET computation by IPET
 * (Implicit Path Enemeration Technique), currently the most successful method to compute WCET.
 * @li @ref ff -- module providing support for flow fact information provided by user
 * or external tools.
 * @li @ref graph -- module providing classes to handle graphs.
 * @li @ref display -- module providing facilities to display graphs.
 * @li @ref application -- module helping to write command line applications.
 *
 * In addition, some utilities are provided:
 * @li @ref dumpcfg -- outputs CFG in different format (textual, .dot).
 * @li @ref odfa -- performs and outputs data flow analysis.
 * @li @ref odisasm -- disassembles of the program and provides information on instructions
 * (semantic instructions, used register, branch targets, etc).
 * @li @ref opcg -- outputs the Program Call Graph (PCG).
 * @li @ref ostat -- computes some statistics about instructions of a program.
 * @li @ref owcet -- computes the WCET based on the scripts.
 * @li @ref operform -- launch the analyses and output the graph without to have to write
 * a script.
 *
 * Finally, some provide specific analyzes:
 * @li ast (@ref ast) -- provide program representation as Abstract Syntactic Trees.
 * @li bpred (@ref bpred) -- branch prediction based on state graphs.
 * @li cat (@ref cat) -- LRU instruction cache analysis by categorization.
 * @li ccg (@ref ccg) -- direct-mapped instruction cache analysis based on state graphs.
 * @li cfgio (@ref cfgio) -- input/output of CFGs.
 * @li dcache (@ref dcache) -- basic LRU data cache analysis.
 * @li etime (@ref etime) -- time determination by block based on parametric execution graph by time set split.
 * @li ets (@ref ets) -- very basic implementation of Extended Timing Schema.
 * @li display (@ref display) -- various display facilities for CFG.
 * @li icat3 (@ef icat3) -- new infrastructure to handle instruction cache analysis.
 *
 * To get answers for developer questions, you can take a look to our @ref faq.
 *
 * @section howto How to read the API ?
 *
 * @subsection howto-struct Structure of OTAWA
 *
 * Built over the C++ class abstraction, OTAWA proposes a layer taking into account the iterative
 * process of analyzing the programs in machine code. Basically, the program is expressed
 * in a form independent of the actual micro-architecture and ISA (Instruction Set Architecture)
 * based on the classes @ref Process, @ref File, @ref Segment and @ref Inst.
 *
 * Each of these objects supports annotations. In OTAWA, an annotation is a piece of information
 * referred and typed by an Identifier and linked to a so-called property list, that is most
 * of objects of the OTAWA program representation. For example, instructions receiving a label
 * get a @ref otawa::LABEL annotation that associates the string naming the label.
 *
 * As long as static analyzes are performed on the program, more and more annotations are
 * tied to the program representation creating two issues: (a) how to chain the analyzes to
 * maintain the soundness of the results and (b) how to cope with the chaos caused
 * by availability of the different annotations provided by the analysis implementations.
 * The implemented solution proposes to group logically annotations together
 * in the so-called @i features. For example, the @ref otawa::LOOP_INFO_FEATURE
 * group together the annotations for identifying loop heads, the exiting edges and
 * the parent loops in the CFG.
 *
 * Finally, the analyzes are packaged in a so-called @i code @i processor,
 * extending the class @ref otawa::Processor,
 * (because they not only perform analyzes but they are able to also changes
 * the program representation). Each code processor applies on the program representation
 * using the annotations provided by other code processors but also generates new annotations
 * that will be useful for the following analyzes. Projected to the domain of features,
 * each code processor requires a set of features before its execution and provide
 * a new set of features.  Notice that most features are associated with a code processor
 * and, hence, the requirement of a code processor may cause the automatic execution
 * of the default code processor of the feature. This system ensures that all required
 * information is provided when a code processor starts its analysis.
 *
 * For example, the @ref otawa::LOOP_INFO_FEATURE is implemented, as a default, by
 * the @ref otawa::LoopInfoBuilder. This one requires, before being started, that the features
 * @ref otawa::DOMINANCE_FEATURE and @ref otawa::INVOLVED_CFG_FEATURE to be available.
 * If they are not, their own default code processor will be automatically called.
 *
 * As a consequence, annotation identifiers, features and code processors have a specific
 * documentation format described here.
 *
 *
 * @subsection howto-id Annotation Identifier Documentation
 * The identifier are used to type and name the annotation put in the property lists,
 * that is, the object representing a program representation. Their documentation follows
 * the example below:
 *
 * @htmlonly
 * <div style="background-color: #FFEB76; display: block; border-style:solid; border-width:1px; padding: 4px; ">
 * <pre>Identifier<BasicBlock*> otawa::ENCLOSING_LOOP_HEADER("otawa::ENCLOSING_LOOP_HEADER", 0)</pre>
 * <p>Defined for any BasicBlock that is part of a loop.
 * Contains the header of the loop immediately containing the basicblock If the basicblock is a loop header, then, the property contains the header of the parent loop.</p>
 * <h3>Hooks</h3>
 * <ul><li>BasicBlock</li></ul>
 *
 * <h3>Feature</h3>
 * <ul><li>otawa::LOOP_INFO_FEATURE</li></ul>
 * </div>
 * @endhtmlonly
 *
 * The first line gives the C++ description of the identifier defining its name, the type of
 * the tied data and its default value (0 here). The two following gives the meaning of
 * the identifier. The @c Hooks gives the list of classes that may support this identifier,
 * @ref otawa::BasicBlock in this case. Finally, the @c Feature paragraph gives the list
 * of feature this identifier belongs to. This last section is optional for identifiers
 * used as configurations for a code processor. In this last case, a @i Configuration
 * replaces the @i Feature section.
 *
 *
 * @subsection howto-feature Feature Documentation
 * A feature is a group of annotation identifiers tied together around a particular topic.
 * It is documented as below:
 *
 * @htmlonly
 * <div style="background-color: #FFEB76; display: block; border-style:solid; border-width:1px; padding: 4px; ">
 * <pre>SilentFeature otawa::dcache::MUST_ACS_FEATURE("otawa::dcache::MUST_ACS_FEATURE", _maker)</pre>
 * <p>This feature ensures that the ACS (Abstract Cache State) for the MUST data cache analysis has been built.
 * Usually, the ACS are used to derivate the categories of each data cache access.</p>
 *
 * <h3>Processors</h3>
 * <ul><li>ACSBuilder (default)</li></ul>
 *
 * <h3>Properties</h3>
 * <ul><li>MUST_ACS</li></ul>
 *
 * <h3>Configuration</h3>
 * <ul><li>ENTRY_MUST_ACS</li></ul>
 * </div>
 * @endhtmlonly
 *
 * After a declaration line containing mainly the name of the feature, several sections give:
 * @li the code processors implementing the feature (and the default code processor),
 * @li the set of properties belonging to the feature (with link to get quickly their
 * documentation),
 * @li the set of properties used as configuration for computing the feature.
 *
 * @subsection howto-proc Code Processor Documentation
 * The code processors performs the analysis using available annotations (whose feature are
 * required by the processor) and provides new one (belonging to the provided features).
 *
 * @htmlonly
 * <div style="background-color: #FFEB76; display: block; border-style:solid; border-width:1px; padding: 4px; ">
 * <pre>otawa::dcache::ACSBuilder Class Reference</pre>
 * <p>...</p>
 * <p>This builder performs analysis of the L1 data cache and produces ACS for MUST and,
 * according to the configuration properties, persistence. As a result, it provides ACS.</p>
 *
 * <h3>Provided features</h3>
 * <ul><li>MUST_ACS_FEATURE</li></ul>
 *
 * <h3>Required features</h3>
 * <ul><li>LOOP_INFO_FEATURE</li>
 * <li>DATA_BLOCK_FEATURE</li></ul>
 *
 * <h3>Configuration</h3>
 * <ul><li>DATA_FIRSTMISS_LEVEL</li>
 * <li>DATA_PSEUDO_UNROLLING</li></ul>
 * </div>
 * @endhtmlonly
 *
 * After the code processor class definition and the definition of its members, a small
 * text describes the function and the algorithm of the code processor. Then several
 * sections gives details about
 * the code processor:
 * @li the list of provided features,
 * @li the list of required features,
 * @li the list of configuration properties.
 *
 *
 * @section develop-otawa Developing with OTAWA
 *
 * Whatever the type of program using OTAWA, the command @ref otawa-config is the right entry
 * point to obtain compilation flags, libraries to link with and installation information.
 * OTAWA is not focused on a particular building (autotools, CMake, etc) but it is important
 * to be able to use @ref otawa-config. Additionally, @ref otawa-config helps to support
 * the plugin management for the most currently used OS as Linux (Unix), Windows and MacOS.
 *
 *
 * @subsection developing-basic Basic Options
 *
 * See @ref application for helper classes to write command line applications.
 *
 * OTAWA provides an API in C++ and to compile a C++ source, just use the flags returned
 * ny @c --cflags option:
 * @code
 * otawa-config --cflags
 * @endcode
 *
 * To link your application, get the options with @c --libs:
 * @code
 * otawa-config --libs
 * @endcode
 *
 * To run the obtained program, ensure that the @c lib directory of OTAWA is found on the
 * system paths. For Unixes, add this directory to the @c $LD_LIBRARY_PATH, it may be obtained
 * by using option @c --prefix and appending @c /lib. On Unixes supporting ELF format and on
 * MacOS, you may also use the @c --rpath option to get this directory linked in the executable
 * @code
 * otawa-config --libs --rpath
 * @endcode
 *
 * On Windows OSes, such facilities do not exist: one solution is to add the OTAWA @c bin
 * directory to the @c @PATH@ system variable or to install your program in the @c bin
 * executable directory of OTAWA (close to the OTAWA main library).
 *
 * Whatever your compilation options, you may also obtain the installation directory of OTAWA
 * with @c --prefix option:
 * @code
 * otawa-config --prefix
 * @endcode
 *
 *
 * @subsection develop-use-plugin Using a plugin
 *
 * OTAWA framework is based on plugins. They are two ways to use identifier, features and
 * processors provided by a plugin: (a) using the DynXXX classes (@ref DynIdentifier,
 * @ref DynFeature or @ref DynProcessor) or (b) by linking dynamically with a plugin binary.
 * The latter form is preferred as soon as you have to use non-inlined method of classes
 * provided by the plugin.
 *
 * To perform the linkage, @ref otawa-config may help also by adding to the command line
 * the list of required plugins (do not forget to give the whole path with components
 * separated by slashes):
 * @code
 * otawa-config --libs path1/plugin1 path2/plugin2 ...
 * @endcode
 *
 * If the @c --rpath option is also given, the path of used plugins is appended to the
 * RPATH list of directories. The paths of the plugin may be absolute or relative to the
 * OTAWA plugin directory. This directory may be obtained by:
 * @code
 * otawa-config --plugdir
 * @endcode
 *
 *
 * @subsection develop-write-plugin Plugin Writing
 *
 * Maybe, the more easy way to extend OTAWA is to write new analyzes and to package them
 * in a package and then to invoke analyzes from a script or from @ref operform.
 * To compile the plugin, the more portable solution consists in providing ``.eld`` file:
 * these files contain information about a plugin in INI format. It is used by OTAWA
 * at run-time to pre-load dependent plugins and libraries whatever the host system
 * without any limitation imposed by the system.
 *
 * Below is the ``.eld`` of the internal module called ``etime`` that computes the time
 * of basic blocks:
 * @code
 * [elm-plugin]
 * name=etime
 * deps=otawa/branch;otawa/dcache
 * @endcode
 *
 * This file gives the ``name`` of the module and provides a list of required plugins,
 * ``deps``: the plugin ``branch`` about branch prediction and the module ``dcache``
 * about data cache analysis. Notice that the paths of required plugins is relative
 * to the OTAWA plugin directory. This directory may be obtained by:
 *
 * Using the ``.eld`` file, the linking flags can be obtained with:
 * @code
 * otawa-config -P PLUGNAME --libs --rpath
 * @endcode
 * With PLUGNAME the name of the built plugin, the name of the ``.eld`` file without
 * ``.eld``.
 *
 * Refer to the ELM documentation about plugins for more details on ``.eld`` files.
 *
 * @subsection develop-newplugin Installing new plugins
 *
 * OTAWA v2 comes with a new installation tool named ``otawa-install.p``. OTAWA may be
 * installed using it but it allows also to automatically add new plugins that are not
 * part of the basic installation.
 *
 * To get the list of installed and available plugins, just type:
 * @code
 * otawa-install.py -l
 * @endcode
 *
 * To install a particular plugin named PLUGIN, just type:
 * @code
 * otawa-install.py PLUGIN
 * @endcode
 *
 * Depending of the availability of binary package for your OS, it will download it
 * and attempt to built the attribute from sources.
 *
 * OTAWA aims to be a very open and versatile framework encouraging third-party module.
 * If you develop your own plugin and if you plan to make it freely available
 * (what we advise), contact us at otawa@irit.fr to add your module in the otawa-install.py
 * module list.
 */


/**
 * @defgroup features Available Features and Processors
 *
 * This page provides quick access to analyzes proposed by OTAWA core.
 * It contains mainly common features and sometimes, when no feature is provided,
 * processor for specific facilities (marked as processors).
 *
 * @par Flow Fact Features
 *
 * @li @ref otawa::FLOW_FACTS_FEATURE
 * @li @ref otawa::MKFF_PRESERVATION_FEATURE
 *
 * @par CFG Features
 *
 * Includes @ref otawa/cfg/features.h
 *
 * @li @ref otawa::CFG_CHECKSUM_FEATURE
 * @li @ref otawa::CFG_INFO_FEATURE
 * @li @ref otawa::CHECKED_CFG_FEATURE
 * @li @ref otawa::COLLECTED_CFG_FEATURE
 * @li @ref otawa::CONTEXT_TREE_FEATURE
 * @li @ref otawa::DEAD_CODE_ANALYSIS_FEATURE
 * @li @ref otawa::DELAYED_CFG_FEATURE
 * @li @ref otawa::DOMINANCE_FEATURE
 * @li @ref otawa::LOOP_HEADERS_FEATURE
 * @li @ref otawa::LOOP_INFO_FEATURE
 * @li @ref otawa::NORMALIZED_CFGS_FEATURE
 * @li @ref otawa::PCG_FEATURE
 * @li @ref otawa::POSTDOMINANCE_FEATURE
 * @li @ref otawa::PST_FEATURE
 * @li @ref otawa::REDUCED_LOOPS_FEATURE
 * @li @ref otawa::UNROLLED_LOOPS_FEATURE
 * @li @ref otawa::VIRTUALIZED_CFG_FEATURE
 *
 * @par IPET Features
 *
 * @li @ref otawa::ipet::ASSIGNED_VARS_FEATURE
 * @li @ref otawa::ipet::BB_TIME_FEATURE
 * @li @ref otawa::ipet::CONTROL_CONSTRAINTS_FEATURE
 * @li @ref otawa::ipet::DATA_CACHE_SUPPORT_FEATURE
 * @li @ref otawa::ipet::FLOW_FACTS_CONSTRAINTS_FEATURE
 * @li @ref otawa::ipet::FLOW_FACTS_FEATURE
 * @li @ref otawa::ipet::ILP_SYSTEM_FEATURE
 * @li @ref otawa::ipet::INST_CACHE_SUPPORT_FEATURE
 * @li @ref otawa::ipet::INTERBLOCK_SUPPORT_FEATURE
 * @li @ref otawa::ipet::OBJECT_FUNCTION_FEATURE
 * @li @ref otawa::ipet::WCET_COUNT_RECORDED_FEATURE
 * @li @ref otawa::ipet::WCET_FEATURE
 *
 * @par Output Features
 *
 * @li @ref otawa::display::CFGOutput (processor)
 * @li @ref otawa::display::ILPSystemDisplayer (processor)
 * @li @ref otawa::ilp::OUTPUT_FEATURE
 *
 * @par Instruction Cache features
 *
 *  * otawa::cache::COLLECTED_LBLOCKS_FEATURE
 *  * otawa::cache::ICACHE_CATEGORY_FEATURE
 *
 *  * otawa::ICACHE_ACS_FEATURE
 *  * otawa::ICACHE_ACS_MAY_FEATURE
 *  * otawa::ICACHE_CATEGORY2_FEATURE
 *  * otawa::ICACHE_CONSTRAINT2_FEATURE;
 *  * otawa::ICACHE_EDGE_ACS_FEATURE
 *  * otawa::ICACHE_EDGE_CATEGORY2_FEATURE
 *  * otawa::ICACHE_FIRSTLAST_FEATURE
 *  * otawa::ICACHE_ONLY_CONSTRAINT2_FEATURE
 *
 * @par Process Features
 *
 * @li @ref otawa::CONTROL_DECODING_FEATURE
 * @li @ref otawa::DECODED_TEXT
 * @li @ref otawa::DELAYED_FEATURE
 * @li @ref otawa::DELAYED2_FEATURE
 * @li @ref otawa::FLOAT_MEMORY_ACCESS_FEATURE
 * @li @ref otawa::MEMORY_ACCESS
 * @li @ref otawa::MEMORY_ACCESS_FEATURE
 * @li @ref otawa::FLOAT_MEMORY_ACCESS_FEATURE
 * @li @ref otawa::REGISTER_USAGE_FEATURE
 * @li @ref otawa::SEMANTICS_INFO
 * @li @ref otawa::SEMANTICS_INFO_EXTENDED
 * @li @ref otawa::SEMANTICS_INFO_FLOAT
 * @li @ref otawa::SOURCE_LINE_FEATURE
 * @li @ref otawa::VLIW_SUPPORTED
 *
 *
 * @par Hardware Configuration Features
 *
 * @li @ref otawa::hard::BHT_FEATURE
 * @li @ref otawa::hard::CACHE_CONFIGURATION_FEATURE
 * @li @ref otawa::hard::MEMORY_FEATURE
 * @li @ref otawa::hard::PROCESSOR_FEATURE
 *
 *
 * @par Data Cache Features (module dcache)
 *
 * Include @ref otawa/dcache/features.h
 * @li @ref otawa::dcache::CATEGORY_FEATURE
 * @li @ref otawa::dcache::CLP_BLOCK_FEATURE
 * @li @ref otawa::dcache::CONSTRAINTS_FEATURE
 * @li @ref otawa::dcache::DATA_BLOCK_FEATURE
 * @li @ref otawa::dcache::DIRTY_FEATURE
 * @li @ref otawa::dcache::MAY_ACS_FEATURE
 * @li @ref otawa::dcache::MUST_ACS_FEATURE
 * @li @ref otawa::dcache::PERS_ACS_FEATURE
 *
 *
 *
 * @par Branch Features (module branch)
 *
 * @li @ref otawa::branch::CATEGORY_FEATURE
 * @li @ref otawa::branch::CONSTRAINTS_FEATURE
 * @li @ref otawa::branch::NUMBERED_CONDITIONS_FEATURE
 * @li @ref otawa::branch::SUPPORT_FEATURE
 *
 * @par Data Flow Features
 *
 * @li @ref otawa::ADDRESS_ANALYSIS_FEATURE
 * @li @ref otawa::clp::CLP_ANALYSIS_FEATURE
 * @li @ref otawa::STACK_ANALYSIS_FEATURE
 */

namespace otawa {

/**
 * @defgroup faq Frequently Asked Questions
 *
 * @par How to get values from the constant sections of the code?
 *
 * In OTAWA, program bytes are considered as constants if they are
 * part of an executable section  or of data section marked as non-writable.
 *
 * The class @ref dfa::State provides a simple to access this information.
 * you have to use first the method isInitialized() to known if the address
 * concerns constant section and then you can use one of get() method to get
 * the actual value.
 *
 * The state is obtainable by the identifier @ref dfa::INITIAL_STATE put on the
 * workspace once the feature @ref dfa::INITIAL_STATE_FEATURE has been provided.
 * Notice that this state object contains also initial values provided
 * by the flow fact files. See @ref ff for more details.
 *
 */

}	// otawa
