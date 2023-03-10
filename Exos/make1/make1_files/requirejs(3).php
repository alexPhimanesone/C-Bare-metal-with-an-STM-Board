/**
 * This file is part of Moodle - http://moodle.org/
 *
 * Moodle is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Moodle is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Moodle.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @package
 * @author    David Castro <david.castro@openlms.net>
 * @copyright Copyright (c) 2017 Open LMS
 * @license   http://www.gnu.org/copyleft/gpl.html GNU GPL v3 or later
 */
define("theme_snap/conversation_badge_count-lazy",["jquery","core/ajax"],(function($,Ajax){var self=this;return self.init=function(userid){self.userid=userid,self.containerEl=$(".conversation_badge_count"),self.queryCount()},self.countUnreadConversations=function(args){var request={methodname:"core_message_get_unread_conversations_count",args:args},promise=Ajax.call([request])[0];return promise.fail(self.resetCount),promise},self.queryCount=function(){self.countUnreadConversations({useridto:self.userid}).then(self.updateCount)},self.updateCount=function(count){count>0?(self.containerEl.text(count),self.containerEl.removeClass("hidden")):(self.containerEl.text(""),self.containerEl.addClass("hidden"))},self.resetCount=function(){self.updateCount(0)},{init:self.init}}));
