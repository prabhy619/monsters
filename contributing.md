## Reporting Issues

**The issue tracker is not a support forum.** Unless you can provide precise *technical information* regarding an issue, you *should not post in it*. If you need support, first read the [FAQ](https://github.com/danpar97/monsters) and then ask in a general GameDev forum such as [/r/GameDev](https://www.reddit.com/r/gamedev/). If you post support questions, generic messages to the developers or vague reports without technical details, they will be closed and locked.

If you believe you have a valid issue report, please post text or a screenshot from the log (the console window that opens alongside monsters) and build version (hex string visible in the titlebar and zip filename), as well as your hardware and software information if applicable.

## Contributing
monsters is a brand new project, so we have a great opportunity to keep things clean and well organized early on. As such, coding style is very important when making commits. We run clang-format on our CI to check the code. Please use it to format your code when contributing. However, it doesn't cover all the rules below. Some of them aren't very strict rules since we want to be flexible and we understand that under certain circumstances some of them can be counterproductive. Just try to follow as many of them as possible:

### General Rules
* A lot of code was taken from other projects (e.g. Dolphin, PPSSPP, Gekko, SkyEye). In general, when editing other people's code, follow the style of the module you're in (or better yet, fix the style if it drastically differs from our guide).
* Line width is typically 100 characters. Please do not use 80-characters.
* Don't ever introduce new external dependencies into Core
* Don't use any platform specific code in Core
* Use namespaces often
* Avoid the use of C-style casts and instead prefer C++-style `static_cast` and `reinterpret_cast`. Try to avoid using `dynamic_cast`. Never use `const_cast`. The only exception to this rule is for casting between two numeric types, where C-style casts are encouraged for brevity and readability.

### Naming Rules
* Functions: `PascalCase`
* Variables: `lower_case_underscored`. Prefix with `g_` if global.
* Classes: `PascalCase`
* Files and Directories: `lower_case_underscored`
* Namespaces: `PascalCase`, `_` may also be used for clarity (e.g. `ARM_InitCore`)

### Indentation/Whitespace Style
Follow the indentation/whitespace style shown below. Do not use tabs, use 4-spaces instead.

### Comments
* For regular comments, use C++ style (`//`) comments, even for multi-line ones.
* For doc-comments (Doxygen comments), use `/// ` if it's a single line, else use the `/**` `*/` style featured in the example. Start the text on the second line, not the first containing `/**`.
* For items that are both defined and declared in two separate files, put the doc-comment only next to the associated declaration. (In a header file, usually.) Otherwise, put it next to the implementation. Never duplicate doc-comments in both places.

```cpp
// Includes should be sorted lexicographically
// STD includes first
#include <map>
#include <memory>

// then, library includes
#include <nihstro/shared_binary.h>

// finally, monsters includes
#include "common/math_util.h"
#include "common/vector_math.h"

// each major module is separated
#include "video_core/pica.h"
#include "video_core/video_core.h"

namespace Example {

// Namespace contents are not indented

// Declare globals at the top
int g_foo{}; // {} can be used to initialize types as 0, false, or nullptr
char* g_some_pointer{}; // Pointer * and reference & stick to the type name, and make sure to initialize as nullptr!

/// A colorful enum.
enum SomeEnum {
    ColorRed,   ///< The color of fire.
    ColorGreen, ///< The color of grass.
    ColorBlue,  ///< Not actually the color of water.
};

/**
 * Very important struct that does a lot of stuff.
 * Note that the asterisks are indented by one space to align to the first line.
 */
struct Position {
    int x{}, y{}; // Always intitialize member variables!
};

// Use "typename" rather than "class" here
template <typename T>
void FooBar() {
    const std::string some_string{ "prefer uniform initialization" };

    int some_array[]{
        5,
        25,
        7,
        42,
    };

    if (note == the_space_after_the_if) {
        CallAfunction();
    } else {
        // Use a space after the // when commenting
    }

    // Place a single space after the for loop semicolons, prefer pre-increment
    for (int i{}; i != 25; ++i) {
        // This is how we write loops
    }

    DoStuff(this, function, call, takes, up, multiple,
            lines, like, this);

    if (this || condition_takes_up_multiple &&
        lines && like && this || everything ||
        alright || then) {

        // Leave a blank space before the if block body if the condition was continued across
        // several lines.
    }

    switch (var) {
    // No indentation for case label
    case 1: {
        int case_var{ var + 3 };
        DoSomething(case_var);
        break;
    }
    case 3:
        DoSomething(var);
        return;

    default:
        // Yes, even break for the last case
        break;
    }

    std::vector<T> you_can_declare, a_few, variables, like_this;
}

}
```

## Typical Git Workflow

This is a guide to a typical Git workflow with monsters. It covers forking from the main repository, creating a branch, keeping your branch up to date with the main repository, resolving conflicts, and merging back into the main repository. It’s not meant to be a hard-and-fast set of rules. However, if you follow something along these lines, you’ll be less likely to piss people off.
It’s appreciated if every single commit in a branch on its own compiles on all supported platforms (Windows, Linux, and OS X) and doesn’t cause any regressions if the commits after it were left unmerged. We understand that with early development, sometimes it’s easier to commit early-and-often, and sometimes you may unintentionally break things (and then later fix them in your branch). If this is part of your workflow, we expect appropriate use of Git rebase to squash broken commits and resolve merge conflicts. If you don’t know how Git rebase works, please read this article before developing for monsters.

### Terminology
* `upstream`: [Main project repository](https://github.com/monsters-emu/monsters)
* `origin`: [Your GitHub forked project repository](e.g. https://github.com/bunnei/monsters)

### Before you begin
* GitHub fork the project
* Clone your GitHub fork locally
```sh
git clone https://github.com/your-username/monsters.git
```
* Grab the submodules
```sh
git submodule update --init --recursive
```
* Set your upstream to the main project repository
```sh
git remote add upstream https://github.com/monsters-emu/monsters.git
```

* Set your Git identity configuration
```sh
git config --global user.name "your-username";
git config --global user.email your-email@example.com
```

### Create a new branch

* Create your branch from the latest upstream/master (Note: please format-branch-names-like-this)
```sh
git fetch upstream && git checkout -b new-branch-name upstream/master
```

* Push your new branch to origin (required later for a pull request)

```sh
git push origin new-branch-name
```

__Scenario A: You did some work in your branch… Then, someone committed something to upstream/master that you want!__

* Make sure you’re on your branch

```sh
git checkout new-branch-name
```

* Rebase upstream/master onto it. With the rebase, move all of your changes to the top, and put all of the new master changes immediately after where you branched from. The goal should be that the branch now appears as though you just created it from upstream/master, and then committed all of your new stuff.

```sh
git rebase upstream/master
```

__Scenario B: You did some more work in your branch… Then, someone committed something to upstream/master that will cause conflicts when trying to get the branch merged back to upstream/master!__

* From your branch, rebase upstream/master
```sh
git checkout new-branch-name
git rebase -i upstream/master
```

Your branch is getting near completion, now you’re ready for a pull request!

* From your branch, rebase upstream/master
```sh
git checkout new-branch-name
git rebase -i upstream/master
```

* Update origin/new-branch-name
```sh
git push origin new-branch-name --force
```

* Create the pull request on GitHub to merge origin/new-branch-name into upstream/master

Gracefully receive feedback from the team

* Address each comment with a commit as needed

Once your pull request is ready to be merged…

* From your branch, interactive rebase to squash all of the new commits (as a result of the pull request feedback) into the commits that they were addressing
```sh
git checkout new-branch-name
git rebase -i HEAD~n
```

* Rebase upstream/master onto your branch to ensure that you have any changes made since your pull request was created
```sh
git rebase -i upstream/master
```

* Update origin/new-branch-name

```sh
git push origin new-branch-name --force
```

* Merge your branch in
* Always merge using the >merge< button in the GitHub pull request
If GitHub says the branch cannot be merged automatically, you’ve likely done something incorrectly (e.g. you did not fully rebase changes from upstream/master into your branch). If things don’t work for you, don’t hesitate to ask us for help @ #monsters on freenode. Mastering Git is not as easy as it might sound, but we’ll happily help you get started.


# Credits
Thanks to [monsters-emu/monsters](https://github.com/monsters-emu/monsters) -> Wiki for such a great git workflow guide
